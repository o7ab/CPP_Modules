#include "Serializer.hpp"

int main()
{
	Data data;
	uintptr_t raw = Serializer::serialize(&data);
	Serializer::deserialize(raw);
	return 0;
}