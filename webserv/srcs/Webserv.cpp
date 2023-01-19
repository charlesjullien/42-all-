#include "../includes/Webserv.hpp"

// quit via signal
bool	quit;

/***********************************************************************/
/*                               SIGNAL                                */
/***********************************************************************/

// catching CTRL C to quit via destructors
void	signalHandler( int signum )
{
	(void)signum;

	quit = true;
}

/***********************************************************************/
/*                        CONSTR DESTR WEBSERV                         */
/***********************************************************************/

// constructor
Webserv::Webserv(std::vector<ServerMembers> &sm)
{
	// init global bool quit
	quit = false;

	// CTRL C to quit properly via destructor
	std::signal(SIGINT, signalHandler);	

	//	Create servers
	for (size_t i = 0; i < sm.size(); ++i)
		servers.push_back(sm[i]);

	//	Init current_sockets with server sockets.
	FD_ZERO(&current_sockets);
	for (size_t i = 0; i < servers.size(); ++i)
		for(std::vector<int>::iterator it = servers[i].sock.begin(); it != servers[i].sock.end(); ++it)
			FD_SET(*it, &current_sockets);
}

// destructor
Webserv::~Webserv(void)
{
	// closing all servers's sockets
	for (size_t i = 0; i < servers.size(); i++)
		for(std::vector<int>::iterator it = servers[i].sock.begin(); it != servers[i].sock.end(); ++it)
			close(*it);
}

/***********************************************************************/
/*                             RUN SERVER                              */
/***********************************************************************/

// run
void Webserv::run()
{
	fd_set						ready_r_sock;
	fd_set						ready_w_sock;

	while (1)
	{
		// if CTRL C is hooked quit properly via destructor
		if (quit == true)
			break ;

		//	Copy because select is destructive.
		ready_r_sock = current_sockets;
		ready_w_sock = current_sockets;

		if (select(FD_SETSIZE, &ready_r_sock, &ready_w_sock, NULL, NULL) < 0 && quit == false)
			throw std::runtime_error("Select failed.");

		//	Check if client asks for connection
		for (size_t i = 0; i < servers.size(); ++i)
		{

			// if CTRL C is hooked quit properly via destructor
			if (quit == true)
				break ;
			
			// if fd is good then create new client socket via accept()
			for(std::vector<int>::iterator it = servers[i].sock.begin(); it != servers[i].sock.end(); ++it)
				if (FD_ISSET(*it, &ready_r_sock))
					servers[i].accept_client(*it, current_sockets);

			//	Check if client asks for connection
			for (std::vector<Client>::iterator cli = servers[i].clients.begin(); 
				cli != servers[i].clients.end(); ++cli)
			{
				// if CTRL C is hooked quit properly via destructor
				if (quit == true)
					break ;

				if (cli->request.is_all_received() == false)
				{
					// if fd is good -> parsing REQUEST
					if (FD_ISSET(cli->sock, &ready_r_sock))
						cli->get_request();
				}

				if (cli->request.is_all_received() == true)
				{
					// if fd is good -> parsing RESPONSE
					if (FD_ISSET(cli->sock, &ready_w_sock))
						servers[i].send_response(*cli);

					// if response is sent
					if (cli->response.is_sent())
					{
						// delete client socket after response is sent
						FD_CLR(cli->sock, &current_sockets);
						close(cli->sock);
						servers[i].clients.erase(cli);
						break ;
					}
				}
			}
		}
	}

}

/***********************************************************************/
/*                            CONSTR SERVER                            */
/***********************************************************************/

//	Server constructor (socket)
Webserv::Server::Server(ServerMembers &sm)
	: members(sm) 
{

	int i = 0;
	for (std::vector<int>::iterator po = sm.port.begin(); po != sm.port.end(); ++po)
	{
		struct sockaddr_in saddr[10000];
		int tmp;

		//	Create socket
		tmp = socket(AF_INET, SOCK_STREAM, 0);
		sock.push_back(tmp); 
		if (tmp < 0)
			throw std::runtime_error("Socket failed.");

		// change sockets to non blocking
		if (fcntl(tmp, F_SETFL, O_NONBLOCK) < 0)
			throw std::runtime_error("Fcntl failed.");

		//	Allow the port to be reusable when restarting
		// setsockopt changes socket options
		int	reuse = 1;
		if (setsockopt(tmp, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0)
			throw std::runtime_error("Setsockopt failed.");

		saddr[i].sin_family = AF_INET;

		saddr[i].sin_port = htons(*po);
			
		saddr[i].sin_addr.s_addr = inet_addr(sm.host.c_str());

		//	Bind gives the socket a local address 
		if (bind(tmp, (struct sockaddr*) &saddr[i], sizeof(saddr[i])) < 0)
			throw std::runtime_error("Bind failed.");
		// listen change the socket state so it can listen to incoming connexions
		if (listen(tmp, 4092) < 0)
			throw std::runtime_error("Listen failed.");

		i++;
	}
}

/***********************************************************************/
/*                          REQUEST RESPONSE                           */
/***********************************************************************/

// get request before sending response
void	Webserv::Client::get_request(void)
{
	// goes to Request.cpp
	request.manage_request(sock);
}

// send response
void	Webserv::Server::send_response(Client &client)
{
	RequestMembers rm = client.request.getRequest();
	
	// goes to Response.cpp
	client.response.manage_response(client.sock, rm);
}

/***********************************************************************/
/*                               CLIENT                                */
/***********************************************************************/

//	Client
Webserv::Client::Client(ServerMembers &sm)
	: response(sm)
{
}

// accept client
void	Webserv::Server::accept_client(int tmpfd, fd_set &current_sockets)
{
	Client	new_client(members);

	// create new client socket connected from socket "sock".
	// if more than one connection are waiting it takes the oldest one
		new_client.sock = accept(tmpfd, 0, 0);
	if (new_client.sock == -1)
		throw std::runtime_error("Accept failed.");

	// fcntl changes the socket to non blocking
	if (fcntl(new_client.sock, F_SETFL, O_NONBLOCK) < 0)
		throw std::runtime_error("Fcntl failed.");

	// push_back in server.client vector
	clients.push_back(new_client);
	FD_SET(new_client.sock, &current_sockets);
}
