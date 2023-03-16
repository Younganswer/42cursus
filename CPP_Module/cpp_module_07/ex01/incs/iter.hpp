#ifndef ITER_HPP
# define ITER_HPP

# include <stddef.h>
# include <iostream>

namespace ft {
	template <typename T>
	void	iter(T *arr, size_t len, void (*f)(const T &)) {
		for (size_t i=0; i<len; i++) {
			f(arr[i]);
		}
	}
	
	template <typename T>
	void	print(const T &ref) {
		std::cout << ref;
	}
}

#endif