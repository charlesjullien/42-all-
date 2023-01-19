#include "../includes/whatever.hpp"


int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

/*int main()
{
	double a = -100.42;
	double b = 1.618;
	swap(a, b);
	std::cout << "a == " << a << ", b == " << b << std::endl;
	std::cout << "min a or b == " << ::min(a, b) << std::endl;
	std::cout << "max a or b == " << ::max(a, b) << std::endl;

	std::cout << std::endl;

	std::string c = "Bonjour";
	std::string d = "Aurevoir";
	swap(c, d);
	std::cout << "c == |" << c << "| && d == |" << d << "|" << std::endl;
	std::cout << "min c or d == " << ::min(c, d) << std::endl;
	std::cout << "max c or d == " << ::max(c, d) << std::endl;

	return (0);	
}*/
