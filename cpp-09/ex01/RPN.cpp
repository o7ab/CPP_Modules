#include "RPN.hpp"

RPN::RPN() : input("")
{
}

RPN::RPN(std::string input) : input(input)
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		input = other.input;
		stack = other.stack;
	}
	return (*this);
}

RPN::~RPN()
{
}

void	RPN::calculate()
{
	if (this->input.empty())
		return ;
	std::istringstream string_stream(input);
	std::string input_str;
	while (string_stream >> input_str)
	{
		if (input_str == "+" || input_str == "-" || input_str == "*" || input_str == "/" || input_str == "%")
		{
			if (stack.size() < 2)
			{
				std::cout << RED << "Error: Not enough values" << RESET << std::endl;
				return ;
			}
			double a = stack.top();
			stack.pop();	
			double b = stack.top();
			stack.pop();
			if (input_str == "+")
				stack.push(b + a);
			else if (input_str == "-")
				stack.push(b - a);
			else if (input_str == "*")
				stack.push(b * a);
			else if (input_str == "/" && b != 0)
				stack.push(b / a);
			else if (input_str == "/" && b == 0)
			{
				std::cout << RED << "Error: Division by zero" << RESET << std::endl;
				return ;
			}
		}
		else if (std::isdigit(input_str[0]))
		{
			double number;
			if (std::atof(input_str.c_str()) < 0 || std::atof(input_str.c_str()) > 9)
			{
				std::cout << RED << "Error: Invalid value" << RESET << std::endl;
				return ;
			}
			number = std::atof(input_str.c_str());
			stack.push(number);
		}
		else
		{
			std::cout << RED << "Error: Invalid value" << RESET << std::endl;
			return ;
		}
	}
	if (stack.size() > 1)
	{
		std::cout << RED << "Error: Too many values" << RESET << std::endl;
		return ;
	}
	std::cout << stack.top() << std::endl;
}