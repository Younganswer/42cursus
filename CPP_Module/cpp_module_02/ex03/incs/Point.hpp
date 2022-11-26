/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:57:33 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 11:55:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		Fixed	_x;
		Fixed	_y;

	public:
		Point(void);
		Point(float x, float y);
		Point(Fixed x, Fixed y);
		Point(const Point &point);
		~Point(void);
		Point	&operator=(const Point &point);

		// Getter
		Fixed		getX(void);
		Fixed		getY(void);
		const Fixed	getX(void) const;
		const Fixed	getY(void) const;

		// Operator Overload
		const Point	operator-(const Point point) const;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif