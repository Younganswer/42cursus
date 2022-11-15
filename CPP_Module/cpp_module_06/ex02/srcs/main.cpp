/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:04:10 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/15 12:12:16 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Base.hpp"
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void) {
	srand(time(NULL));
	Base	*base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return (0);
}