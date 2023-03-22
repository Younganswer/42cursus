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
};

// toString
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif