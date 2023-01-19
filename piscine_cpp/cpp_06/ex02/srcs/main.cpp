#include "../includes/type_info.hpp"

int main(int ac, char **av)
{
	Base *base = generate();
	identify(base);
	identify(*base);

	delete base;
	
	return (0);	
}
