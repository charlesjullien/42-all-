#ifndef SERIALISATION_HPP
# define SERIALISATION_HPP

#include <iostream>
#include <string>

typedef struct s_Data	Data;
struct			s_Data
{
	std::string lol;
	double 		n1;
	int			n2;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif