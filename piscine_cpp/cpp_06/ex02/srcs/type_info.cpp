#include "../includes/type_info.hpp"

Base * generate(void)
{
	int rand = std::rand() % 3;
	Base *base;

	if (rand == 0)
		base = new A;
	else if (rand == 1)
		base = new B;
	else
		base = new C;
	return (base);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(...) {}
}

Base::~Base()
{

}

