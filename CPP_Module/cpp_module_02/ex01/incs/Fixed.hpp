/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/11 11:52:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class Fixed {
private:
	static const int	fractional_bits = 8;
	int					raw_bits;

public:
	Fixed(void);
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed &fixed);
	Fixed	&operator=(const Fixed &fixed);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif