/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:20:57 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 15:50:48 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		std::cout << ref << '\n';
	}
}

#endif