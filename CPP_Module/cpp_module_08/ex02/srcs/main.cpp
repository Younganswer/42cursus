/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:34:49 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 18:08:17 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../incs/MutantStack.hpp"

int	main(void) {
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);
		
		std::cout << "stack.top(): " << mstack.top() << '\n';

		mstack.pop();

		std::cout << "stack.size(): " << mstack.size() << '\n';

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();

		++it;
		--it;

		while (it != ite) {
			std::cout << *it << ' ';
			++it;
		}
		std::cout << '\n';
		
		std::stack<int>	s(mstack);
	}
	{
		MutantStack<std::string>	mstack;

		mstack.push("Hello");
		mstack.push("World");

		std::cout << "stack.top(): " << mstack.top() << '\n';

		mstack.pop();

		std::cout << "stack.size(): " << mstack.size() << '\n';

		mstack.push("World");
		mstack.push("Hello");
		mstack.push("42");
		mstack.push("!");
		
		MutantStack<std::string>::iterator	it = mstack.begin();
		MutantStack<std::string>::iterator	ite = mstack.end();

		++it;
		--it;

		while (it != ite) {
			std::cout << *it << ' ';
			++it;
		}
		std::cout << '\n';
		
		std::stack<std::string>	s(mstack);
	}
	return (0);
}