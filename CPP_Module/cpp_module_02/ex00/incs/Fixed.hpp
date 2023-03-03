#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		static const int	_fractional_bits = 8;
		int					_raw_bits;

	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		~Fixed(void);
		Fixed	&operator=(const Fixed &fixed);

		// Getter
		int		getRawBits(void) const;

		// Setter
		void	setRawBits(const int raw);
};

#endif