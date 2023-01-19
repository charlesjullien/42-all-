#ifndef ITER_HPP
#define ITER_HPP
#include <iomanip>
#include <iostream>
#include <string>


template <typename T>
void print(T element)
{
    std::cout << element << std::endl;
}

template <typename T>
void iter(T *tab, unsigned int size, void (function)(T))
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		function(tab[i]);
		i++;
	}
}


#endif