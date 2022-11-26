/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:05:19 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 11:58:04 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.hpp"

bool			bsp(const Point a, const Point b, const Point c, const Point point);
static float	cross_product(const Point &vector1, const Point &vector2);

bool	bsp(const Point a, const Point b, const Point c, const Point point) {
	float	direction;

	if ((direction = cross_product(b-a, point-a)) == 0 || \
		(direction * cross_product(c-b, point-b) <= 0) || \
		(direction * cross_product(a-c, point-c) <= 0))
		return (false);
	return (true);
}

static float	cross_product(const Point &vector1, const Point &vector2) {
	return (Fixed(vector1.getX()*vector2.getY()-vector1.getY()*vector2.getX()).toFloat());
}