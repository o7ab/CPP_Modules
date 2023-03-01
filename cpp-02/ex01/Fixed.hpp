#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
class Fixed
{
	private:
		int fixedPointValue;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(Fixed const & src);
		Fixed(const int & src);
		Fixed(const float & src);
		~Fixed();
		Fixed & operator=(Fixed const & rhs);
		
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream & operator << (std::ostream &out, const Fixed &c);

# endif