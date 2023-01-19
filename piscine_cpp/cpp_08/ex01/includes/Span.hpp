#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <string>
#include <stack>
#include <list>
#include <algorithm>
#include <ctime>

class Span
{

	class outOfRange : public std::exception
    {
		public :

        virtual const char *what() const throw()
		{
			return ("Error : what you ask is out of range.");
		}
    };

	public : 

	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	unsigned int getN();
	std::vector<int> getTab();

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	private :

	unsigned int N;
	std::vector<int> tab;
	Span(); // Je le met en privé pour qu'on ne puisse construire un objet qu'avec un n (surchargé) depuis le main.
};


#endif