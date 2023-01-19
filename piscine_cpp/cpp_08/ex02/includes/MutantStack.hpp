#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
	
	MutantStack();
	MutantStack(const MutantStack<T> &other);
	MutantStack &operator=(const MutantStack<T> &other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other)
{
	*this = other;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
    this->c = other.c;
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator  MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator  MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (this->c.end());
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	
}

#endif