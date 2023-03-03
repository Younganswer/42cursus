#include "../incs/Point.hpp"

bool			bsp(const Point a, const Point b, const Point c, const Point point);
static float	cross_product(const Point &vec1, const Point &vec2);

bool	bsp(const Point a, const Point b, const Point c, const Point point) {
	float	direction;

	return (
		(0 != (direction = cross_product(b-a, point-a)) && \
		0 < (direction * cross_product(c-b, point-b)) && \
		0 < (direction * cross_product(a-c, point-c)))
	);
}

static float	cross_product(const Point &vec1, const Point &vec2) {
	return (Fixed(vec1.getX()*vec2.getY()-vec1.getY()*vec2.getX()).toFloat());
}