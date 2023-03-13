#ifndef SCALARCONVERTOR_HPP
# define SCALARCONVERTOR_HPP


#include <iostream>
#include <cstdlib>
#include <exception>

class ScalarConvertor
{
	public:
		ScalarConvertor();
		ScalarConvertor(ScalarConvertor const & src);
		~ScalarConvertor();
		ScalarConvertor & operator=(ScalarConvertor const & rhs);
		static void convert(std::string const & str);
};



#endif