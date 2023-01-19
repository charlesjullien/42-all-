NAME = inception

all:
		cat /etc/hosts | if ! grep -P "127.0.0.1\tcjullien.42.fr"; then sudo sh -c 'echo "127.0.0.1\tcjullien.42.fr" >> /etc/hosts'; fi
		sudo mkdir -p /home/cjullien/data/wordpress
		sudo mkdir -p /home/cjullien/data/mariadb
		docker-compose -f srcs/docker-compose.yml up -d --build

start:
		docker-compose -f srcs/docker-compose.yml start

stop:
		docker-compose -f srcs/docker-compose.yml stop

clean:
		docker-compose -f srcs/docker-compose.yml down
fclean:
		docker-compose -f srcs/docker-compose.yml down --rmi all -v
		docker system prune -a -f
		sudo rm -rf /home/cjullien/data
		#docker rmi -f $(docker images –filter "dangling=true" -q –no-trunc) 2> /dev/null
		#https://stackoverflow.com/questions/45142528/what-is-a-dangling-image-and-what-is-an-unused-image#:~:text=Dangling%20images%20are%20layers%20that,docker%20images%20%2Df%20dangling%3Dtrue
		#https://jacace.wordpress.com/2016/10/27/how-to-clean-up-dangling-intermediate-docker-images/

.PHONY: all start stop clean fclean