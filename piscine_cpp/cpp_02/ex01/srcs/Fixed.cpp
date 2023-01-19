#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	fixed_point_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point_value = n << fract_bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point_value = roundf(n * F_POINT);
}

int Fixed::toInt(void) const
{
	return (fixed_point_value >> fract_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)fixed_point_value/F_POINT);
}


Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixed_point_value = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
	fixed_point_value = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}
