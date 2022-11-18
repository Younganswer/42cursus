/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:17:26 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 15:50:09 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

namespace ft {
	template <typename T>
	void	swap(T &a, T &b) {
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <typename T>
	const T &min(const T &a, const T &b) {
		return (a < b ? a : b);
	}

	template <typename T>
	const T &max(const T &a, const T &b) {
		return (a > b ? a : b);
	}
}

#endif