#include "../includes/iter.hpp"

int main()
{
    std::string tab1[] = {"Hello", "World", "!", "How", "are", "you", "today", "..?"};
	double tab2[] = {1.618, 3.14, 51.51, 19.19, 17.17};
    int tab3[] = {0, 1, 2, 3, 4, 6, 6, 7, 8, 9, 10};

    iter(tab1, 8, print);
	std::cout << std::endl;
    iter(tab2, 5, print);
	std::cout << std::endl;
    iter(tab3, 11, print);

	return (0);
}