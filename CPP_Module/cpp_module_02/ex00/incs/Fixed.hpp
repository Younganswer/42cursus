/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/10 14:38:00 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
	static const int	fractional_bits = 8;
	int					raw_bits;

public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	Fixed	&operator=(const Fixed &fixed);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};

#endif