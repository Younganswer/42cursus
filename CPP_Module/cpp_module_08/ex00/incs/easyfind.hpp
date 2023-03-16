#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	typename T::iterator it = container.begin();

	while (it != container.end()) {
		if (*it == n) {
			break;
		}
		it++;
	}
	return (it);
}

#endif