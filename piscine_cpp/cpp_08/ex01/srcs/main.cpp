#include "../includes/Span.hpp"

int main()
{

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;


	Span test = Span(10);
	test.addNumber(-1000);
	test.addNumber(1000);
	test.addNumber(3000);
	test.addNumber(100);
	test.addNumber(5);
	test.addNumber(50);
	test.addNumber(650);
	test.addNumber(500);
	test.addNumber(350);
	test.addNumber(250);
	try
	{
		test.addNumber(59);//11
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;

	Span big = Span(10000);
	std::srand(std::time(NULL));
	unsigned int rand = std::rand();
	int i = 0;
	while (i < 10000)
	{
		rand = std::rand();
		big.addNumber(rand);
		i++;
	}
	
	std::cout << std::endl;
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;


	return 0;
}