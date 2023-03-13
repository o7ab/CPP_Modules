#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *data)
{
	data->s1 = "Hello";
	data->n = 42;
	data->s2 = "World";
	return reinterpret_cast<uintptr_t>(data);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *data = reinterpret_cast<Data *>(raw);
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;
	return data;
}

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const & src)
{
	*this = src;
}

Serializer::~Serializer()
{
}

Serializer & Serializer::operator=(Serializer const & rhs)
{
	(void)rhs;
	return *this;
}
