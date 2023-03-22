#include "Span.hpp"

Span::Span(unsigned int n)
{
	array.reserve(n);
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
	this->array.push_back(n);

	for (size_t i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int		Span::shortestSpan()
{
	try {
		if (this->array.size() < 2)
			throw Span::NoSpanException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	std::vector<int>	tmp = this->array;
	std::sort(tmp.begin(), tmp.end());
	int					min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
		// std::cout << "min: " << min << std::endl;
	}
	return (min);
}

int		Span::longestSpan()
{
	try{
		if (this->array.size() < 2)
			throw Span::NoSpanException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	std::vector<int>	tmp = this->array;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

void	Span::AddRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	this->array.insert(this->array.end(), begin, end);
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Array is empty or has only one element");
}
