#ifndef Array_HPP
#define Array_HPP
#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

template <class T>
class Array
{
	private :

	unsigned int n; //nb d'éléments dans l'Array
	T *array;

	public : 

	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array<T> &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int index);
	unsigned int size()
	{
		return (this->n);
	}

};

template <class T>
Array<T>::Array()
{
    n = 0;
    this->array = new T[0];
}

template <class T>
Array<T>::Array(unsigned int n_)
{
	unsigned int i;

	i = 0;
	n = n_;
    this->array = new T[n_];
	while (i < n_)
	{
		this->array[i] = 0;
		i++;
	}
}

template <class T>
Array<T>::Array(const Array &other)
{
    *this = other;
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other)
{
	unsigned int i;

	i = 0;
    this->n = other.n;
    this->array = new T[n];
	while (i < n)
	{
        this->array[i] = other.array[i];
		i++;
	}
    return (*this);
}

template <class T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= this->n || index < 0)
        throw std::exception();
    return (array[index]);
}

template <class T>
Array<T>::~Array()
{
	delete[] this->array;
}

#endif