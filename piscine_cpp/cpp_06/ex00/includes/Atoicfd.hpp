#ifndef ATOICFD_HPP
# define ATOICFD_HPP

#include <iostream>
#include <string>
#include <climits>
#include <iomanip>

class Atoicfd
{
	public:

	Atoicfd();
	Atoicfd(std:: string a);
	Atoicfd(const Atoicfd &other);
	Atoicfd &operator=(const Atoicfd &other);
	~Atoicfd();

	bool convertible(std::string a);

	bool check_int(std::string a);

	bool check_double(std::string a);
	bool check_double_infnan(std::string a);

	bool check_float(std::string a);
	bool check_float_inffnanf(std::string a);

	private:

	std::string 	_a;
	unsigned int 	_a_len;
	char 			_c;
	long int 		_i;
	double 			_d;
	float 			_f;

};

#endif
