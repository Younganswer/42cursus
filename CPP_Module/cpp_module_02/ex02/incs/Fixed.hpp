#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		static const int	_fractional_bits = 8;
		int					_raw_bits;

	public:
		Fixed(void);
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &ref);
		~Fixed(void);
		Fixed	&operator=(const Fixed &rhs);

		// Getter
		int		getRawBits(void) const;

		// Setter
		void	setRawBits(const int raw);

		// Utils
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed		&min(Fixed &fixed1, Fixed &fixed2);
		static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
		static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);

		// Operator Overload
		bool	operator<(const Fixed &rhs) const;
		bool	operator>(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;
		Fixed	operator++(int);
		Fixed	&operator++(void);
		Fixed	operator--(int);
		Fixed	&operator--(void);
};

// toString
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif