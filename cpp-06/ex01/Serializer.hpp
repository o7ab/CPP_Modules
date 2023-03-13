#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

typedef struct s_Data
{
	std::string s1;
	int n;
	std::string s2;
}				Data;

class Serializer
{
	public:
		Serializer();
		Serializer(Serializer const & src);
		~Serializer();
		Serializer & operator=(Serializer const & rhs);
		static uintptr_t serialize(Data *data);
		static Data *deserialize(uintptr_t raw);
};

#endif