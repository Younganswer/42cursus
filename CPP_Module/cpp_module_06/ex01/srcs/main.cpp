/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:04:10 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/12 22:12:26 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Data.hpp"

int	main(void) {
	Data *data = new Data("Hello", "World", 42);

	uintptr_t raw = serialize(data);
	Data *deserialized = deserialize(raw);
	std::cout << deserialized->s1 << ' ' << deserialized->s2 << '\n';
	std::cout << deserialized->n << '\n';

	delete data;
	return (0);
}