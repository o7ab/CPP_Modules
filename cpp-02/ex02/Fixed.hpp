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
		bool	operator==(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const ;
		bool	operator>(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;
		Fixed	operator+(Fixed const & rhs);
		Fixed	operator-(Fixed const & rhs);
		Fixed	operator*(Fixed const & rhs);
		Fixed	operator/(Fixed const & rhs);
		float	toFloat() const;
		int		toInt() const;
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed & operator++(void);
		Fixed & operator--(void);
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
		static Fixed & min(Fixed &lhs, Fixed &rhs);
		static Fixed & max(Fixed  &lhs, Fixed &rhs);
		static const Fixed & min(Fixed const &lhs, Fixed const &rhs);
		static const Fixed & max(Fixed const &lhs, Fixed const &rhs);

};

std::ostream & operator << (std::ostream &out, const Fixed &c);

# endif