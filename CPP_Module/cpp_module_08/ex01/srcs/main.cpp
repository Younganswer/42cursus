/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:34:49 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 17:04:55 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../incs/Span.hpp"

int	main(void) {
	{
		Span	sp = Span(5);

		try {
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.printVec();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Shortest Span: " << sp.shortestSpan() << '\n';
			std::cout << "Longest Span: " << sp.longestSpan() << '\n';
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span	sp = Span(5);

		try {
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(11);
			sp.addNumber(11);
			sp.printVec();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Shortest Span: " << sp.shortestSpan() << '\n';
			std::cout << "Longest Span: " << sp.longestSpan() << '\n';
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span	sp = Span(5);

		try {
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(15);
			sp.printVec();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Shortest Span: " << sp.shortestSpan() << '\n';
			std::cout << "Longest Span: " << sp.longestSpan() << '\n';
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span	sp = Span(5);

		try {
			sp.addNumber(5);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Shortest Span: " << sp.shortestSpan() << '\n';
			std::cout << "Longest Span: " << sp.longestSpan() << '\n';
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}