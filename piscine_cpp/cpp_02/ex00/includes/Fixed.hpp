#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:

	Fixed();
	Fixed(const Fixed &other);
	~Fixed();

	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);

	private:

	int fixed_point_value;
	static const int fract_bits = 8;
	
};

#endif
