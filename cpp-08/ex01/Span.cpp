#include "Span.hpp"

Span::Span(unsigned int n) : array(n)
{
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span()
{
}

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->array = rhs.array;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->array.size() == this->array.capacity())
		throw Span::FullArrayException();
	this->array.push_back(n);
}

int		Span::shortestSpan()
{
	if (this->array.size() < 2)
		throw Span::NoSpanException();
	std::vector<int>	tmp = this->array;
	std::sort(tmp.begin(), tmp.end());
	int					min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	}
	return (min);
}

int		Span::longestSpan()
{
	if (this->array.size() < 2)
		throw Span::NoSpanException();
	std::vector<int>	tmp = this->array;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::FullArrayException::what() const throw()
{
	return ("Array is full");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Array is empty or has only one element");
}
