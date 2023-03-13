#include "ScalarConvertor.hpp"

ScalarConvertor::ScalarConvertor()
{
}

ScalarConvertor::ScalarConvertor(ScalarConvertor const & src)
{
	*this = src;
}

ScalarConvertor::~ScalarConvertor()
{
}

ScalarConvertor & ScalarConvertor::operator=(ScalarConvertor const & rhs)
{
	(void)rhs;
	return *this;
}

void	ScalarConvertor::convert(std::string const & str)
{
	try
	{
		if (str == "nan" || str == "nanf" || str == "inff" || str == "inf" || str == "-inff" || str == "-inf")
			throw std::exception();
		int		i = std::atoi(str.c_str());
		float	f = static_cast<float>(std::atof(str.c_str()));
		double	d = std::atof(str.c_str());
		char	c = static_cast<char>(i);
		std::cout << "char: ";
		if (i < 32 || i > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
