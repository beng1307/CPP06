#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	Base	*base = Base::generate();

	Base::identify(base);
	Base::identify(*base);

	delete	base;
}