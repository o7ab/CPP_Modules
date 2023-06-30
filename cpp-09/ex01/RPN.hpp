#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"
class RPN
{
	private:
		std::stack<double> stack;
		std::string input;
	public:
	RPN();
	RPN(std::string input);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	void calculate();
	~RPN();
};

#endif