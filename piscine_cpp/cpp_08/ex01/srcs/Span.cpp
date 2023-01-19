#include "../includes/Span.hpp"

Span::Span()
{

}

Span::Span(unsigned int n)
{
	this->N = n;
}

Span::Span(const Span &other)
{
    *this = other;
}

Span& Span::operator=(const Span &other)
{
    this->N = other.N;
    this->tab = other.tab;
    return(*this);
}

unsigned int Span::getN()
{
	return (this->N);
}

std::vector<int> Span::getTab()
{
	return (this->tab);
}

void Span::addNumber(int num)
{
	if (this->tab.size() < this->N)
	{
		this->tab.push_back(num);
	}
	else
	{
		throw (outOfRange());
	}
}

int Span::shortestSpan()
{
	int curr;
	int next;
	int range;
	std::vector<int> temp;
	if (this->tab.size() <= 1)
	{
		throw (outOfRange());
		return (0);
	}
	temp = this->tab;
    std::sort(temp.begin(), temp.end());
	std::vector<int>::iterator	iter_begin;
	iter_begin = temp.begin();
	range = temp[1] - temp[0];
	while (*iter_begin != temp[temp.size() - 1])
	{
		curr = *iter_begin;
		iter_begin++;
		next = *iter_begin;
		if (range > (next - curr))
			range = next - curr;
	}
	return (range);
}

int Span::longestSpan()
{
	if (this->tab.size() <= 1)
	{
		throw (outOfRange());
		return (0);
	}
	std::vector<int> temp;

    temp = this->tab;
    sort(temp.begin(), temp.end());
	return (temp[temp.size() - 1] - temp[0]);
}

Span::~Span()
{
	
}