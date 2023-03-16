#include "../incs/MutantStack.hpp"
#include <iostream>
#include <string>

int	main(void) {
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);
		
		std::cout << "Current size of mstack: " << mstack.size() << '\n';
		std::cout << "Top of mstack: " << mstack.top() << '\n';

		mstack.pop();

		std::cout << "Current size of mstack after popping: " << mstack.size() << '\n';
		std::cout << "Top of mstack after popping: " << mstack.top() << '\n';

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator	it = mstack.begin();

		++it;
		--it;

		std::cout << "mstack: ";
		while (it != mstack.end()) {
			std::cout << *it << ' ';
			++it;
		}
		std::cout << '\n';
		
		std::stack<int>	s(mstack);
	}
	std::cout << '\n';
	{
		MutantStack<std::string>	mstack;

		mstack.push("Hello");
		mstack.push("World");

		std::cout << "Current size of mstack: " << mstack.size() << '\n';
		std::cout << "Top of mstack: " << mstack.top() << '\n';

		mstack.pop();

		std::cout << "Current size of mstack after popping: " << mstack.size() << '\n';
		std::cout << "Top of mstack after popping: " << mstack.top() << '\n';

		mstack.push("World");
		mstack.push("Hello");
		mstack.push("42");
		mstack.push("!");
		
		MutantStack<std::string>::iterator	it = mstack.begin();

		++it;
		--it;

		std::cout << "mstack: ";
		while (it != mstack.end()) {
			std::cout << *it << ' ';
			++it;
		}
		std::cout << '\n';
		
		std::stack<std::string>	s(mstack);
	}
	return (0);
}