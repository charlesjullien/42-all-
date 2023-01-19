#ifndef FIXED_HPP
# define FIXED_HPP

#define F_POINT (1 << 8)

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:

	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();

	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);

	int toInt(void) const;
	float toFloat(void) const;

	private:

	int fixed_point_value;
	static const int fract_bits = 8;
	
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
