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

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixed_point_value = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed_point_value = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}