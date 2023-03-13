#include "Base.hpp"

int main()
{
	Base *base;
	base = Base::generate();
	Base::identify(base);
	Base::identify(*base);
	return 0;
}