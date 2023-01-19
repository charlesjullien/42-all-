#include "../includes/main.hpp"

std::string scan_line(std::string line, std::string search, std::string replace)
{
	unsigned int i = 0;
	unsigned int j = 0;

	while (line[i])
	{
		j = 0;
		while (search[j] == line[i + j])
			j++;
		if (j == search.length())
		{
			line.erase(i, search.length());
			line.insert(i, replace);
			i += replace.length();
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (line);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Please launch the program as follow : ./S_and_R file searched_string replace_string" << std::endl;
		return (1);
	}

	std::string search = av[2];
	std::string replace = av[3];
	std::string new_filename = av[1];
	new_filename += ".replace";
	const char * c = new_filename.c_str();
	std::string line;

	if (!search.length() || !replace.length())
	{
		std::cerr << "search str and replace str must not be empty" << std::endl;
		return (1);
	}

	std::ifstream rd;
	rd.open(av[1], std::ifstream::in);
	if (rd.is_open())
	{
		std::ofstream wr;
		wr.open(c, std::ios::out | std::ios::trunc);
		while (std::getline(rd, line))
		{
			line = scan_line(line, search, replace);
			wr << line << std::endl;
			wr.clear();
		}
		rd.close();
		wr.close();
	}
	return (0);
}