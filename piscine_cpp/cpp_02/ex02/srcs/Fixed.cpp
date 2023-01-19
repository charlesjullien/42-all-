#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const int n)
{
	fixed_point_value = n << fract_bits;
}

Fixed::Fixed(const float n)
{
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
	
}

/******************************************************/
/******************************************************/
/******************************************************/
/******************************************************/

bool Fixed::operator>(Fixed const &N) const 
{
	return this->fixed_point_value > N.fixed_point_value;
}

bool Fixed::operator<(const Fixed &N) const 
{
	return this->fixed_point_value < N.fixed_point_value;
}

bool Fixed::operator>=(const Fixed &N) const 
{
	return this->getRawBits() >= N.getRawBits();
}

bool Fixed::operator<=(const Fixed &N) const 
{
	return this->getRawBits() <= N.getRawBits();;
}

bool Fixed::operator==(const Fixed &N) const 
{
	return this->getRawBits() == N.getRawBits();;
}

bool Fixed::operator!=(const Fixed &N) const 
{
	return !(*this == N);
}

Fixed Fixed::operator+(const Fixed &N) const 
{
	return Fixed(this->toFloat() + N.toFloat());
}

Fixed Fixed::operator-(const Fixed &N) const 
{
	return Fixed(this->toFloat() - N.toFloat());
}

Fixed Fixed::operator*(const Fixed &N) const 
{
	return Fixed(this->toFloat() * N.toFloat());
}

Fixed Fixed::operator/(const Fixed &N) const 
{
	if(N.toInt() > 0)
		return Fixed(this->toFloat() / N.toFloat());
	else throw std::runtime_error("Cannot divide by zero");
}

Fixed Fixed::operator++(int) 
{
	Fixed fixed(*this);
	++fixed_point_value;
	return fixed;
}

Fixed &Fixed::operator++() 
{
	this->fixed_point_value++;
	return *this;
}

Fixed Fixed::operator--(int) 
{
	Fixed fixed(*this);
	--fixed_point_value;
	return fixed;
}

Fixed &Fixed::operator--() 
{
	this->fixed_point_value--;
	return *this;
}

Fixed &Fixed::min(Fixed &N1, Fixed &N2) 
{
	if(N1.fixed_point_value < N2.fixed_point_value) return N1;
	else return N2;
}

const Fixed &Fixed::min(const Fixed &N1, const Fixed &N2) {
	if(N1.fixed_point_value < N2.fixed_point_value) return N1;
	else return N2;
}

Fixed &Fixed::max(Fixed &N1, Fixed &N2) 
{
	if(N1.fixed_point_value > N2.fixed_point_value) return N1;
	else return N2;
}

const Fixed &Fixed::max(const Fixed &N1, const Fixed &N2) 
{
	if(N1.fixed_point_value > N2.fixed_point_value)
		return N1;
	else
		return N2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
