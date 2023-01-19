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

	bool operator>(const Fixed &N) const;

	bool operator<(const Fixed &N) const;

	bool operator>=(const Fixed &N) const;

	bool operator<=(const Fixed &N) const;

	bool operator==(const Fixed &N) const;

	bool operator!=(const Fixed &N) const;

	Fixed operator+(const Fixed &N) const;

	Fixed operator-(const Fixed &N) const;

	Fixed operator*(const Fixed &N) const;

	Fixed operator/(const Fixed &N) const;

	Fixed operator++(int);

	Fixed &operator++();

	Fixed operator--(int);

	Fixed &operator--();

	static Fixed &min(Fixed &N1, Fixed &N2);

	static const Fixed &min(const Fixed &N1, const Fixed &N2);

	static Fixed &max(Fixed &N1, Fixed &N2);

	static const Fixed &max(const Fixed &N1, const Fixed &N2);

	private:

	int fixed_point_value;
	static const int fract_bits = 8;
	
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
