#include "../includes/Atoicfd.hpp"

Atoicfd::Atoicfd()
{

}

bool Atoicfd::check_int(std::string a)
{
	int i = 0;

	if (a[0] == '+' || a[0] == '-')
		i++;
	while (i < _a_len)
	{
		if (!isdigit(a[i]))
			return (false);
		i++;
	}
	return (true);
}

bool Atoicfd::check_double(std::string a)
{
	int i = 0;
	int point = 0;

	if (a[0] == '+' || a[0] == '-')
		i++;
	while (i < _a_len)
	{
		if (a[i] == '.')
			point++;
		if (!isdigit(a[i]) && a[i] != '.')
			return (false);
		i++;
	}
	if (point > 1)
		return (false);
	return (true);
}

bool Atoicfd::check_double_infnan(std::string a)
{
	if (a == "nan")
		return (true);
	else if (a == "-inf")
		return (true);
	else if (a == "inf")
		return (true);
	else if (a == "+inf")
		return (true);
	else
		return (false);
}

bool Atoicfd::check_float(std::string a)
{
	int i = 0;
	int point = 0;

	if (a[_a_len - 1] != 'f')
		return (false);
	if (a[0] == '+' || a[0] == '-')
		i++;
	while (i < _a_len - 1)
	{
		if (a[i] == '.')
			point++;
		if (!isdigit(a[i]) && a[i] != '.')
			return (false);
		i++;
	}
	if (point > 1)
		return (false);
	return (true);
}

bool Atoicfd::check_float_inffnanf(std::string a)
{
	if (a == "nanf")
		return (true);
	else if (a == "-inff")
		return (true);
	else if (a == "inff")
		return (true);
	else if (a == "+inff")
		return (true);
	else
		return (false);
}

bool Atoicfd::convertible(std::string a)
{
	if (_a_len == 1 && !isdigit(a[0]))// == check_char();
	{
		_c = a[0];
		_i = static_cast<long>(_c);
		_d = static_cast<double>(_c);
		_f = static_cast<float>(_c);
	}
	else if (check_int(a) == true)
	{
		_i = std::stol(a);
		_c = static_cast<char>(_i);
		_d = static_cast<double>(_i);
		_f = static_cast<float>(_i);
	}
	else if (check_double(a) == true || check_double_infnan(a) == true)
	{
		_d = std::stod(a);
		_c = static_cast<char>(_d);
		_i = static_cast<long>(_d);
		_f = static_cast<float>(_d);
	}
	else if (check_float(a) == true || check_float_inffnanf(a) == true)
	{
		_f = std::stof(a);
		_c = static_cast<char>(_f);
		_i = static_cast<long>(_f);
		_d = static_cast<double>(_f);
	}
	else
		return (false);
	return (true);
}

Atoicfd::Atoicfd(std::string a)
{
	_a = a;
	_a_len = a.length();

	if (convertible(a))
	{
		if (isprint(_c) && _i > 0 && _i < 127)
			std::cout << "char: '" << _c << "'" << std::endl;
		else if (_i < 0 || _i >= 127)
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(_c))
			std::cout << "char: Non displayable" << std::endl;
		if (INT_MAX < _i || INT_MIN > _i || check_double_infnan(a) == true ||
			check_float_inffnanf(a) == true)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << _i << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << _f << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << _d << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: impossible" << std::endl;

	}
}

Atoicfd::Atoicfd(const Atoicfd &other)
{
	*this = other;
}

Atoicfd &Atoicfd::operator=(const Atoicfd &other)
{
	return (*this);
}

Atoicfd::~Atoicfd()
{

}

