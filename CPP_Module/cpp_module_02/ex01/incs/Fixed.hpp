/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/30 16:42:43 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class Fixed {
	private:
		static const int	_fractional_bits = 8;
		int					_raw_bits;
	
	public:
		Fixed(void);
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &fixed);
		~Fixed(void);
		Fixed	&operator=(const Fixed &fixed);
	
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