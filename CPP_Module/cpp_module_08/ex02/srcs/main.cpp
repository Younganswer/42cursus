#include "../incs/MutantStack.hpp"
#include <iostream>
#include <string>
#include <vector>

template <typename T>
bool	printMutantStack(const MutantStack<T> &mstack);

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
		
		printMutantStack(mstack);
		
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
		
		printMutantStack(mstack);

		std::stack<std::string>	s(mstack);
	}
	std::cout << '\n';
	{
		std::vector<std::string>	vec;

		vec.push_back("Hello");
		vec.push_back("World");

		std::cout << "Current size of vec: " << vec.size() << '\n';
		std::cout << "Back of vec: " << vec.back() << '\n';

		vec.pop_back();

		std::cout << "Current size of vec after popping: " << vec.size() << '\n';
		std::cout << "Back of vec after popping: " << vec.back() << '\n';

		vec.push_back("World");
		vec.push_back("Hello");
		vec.push_back("42");
		vec.push_back("!");
		
		std::cout << "vec:";
		for (std::vector<std::string>::const_iterator it=vec.begin(); it!=vec.end(); it++) {
			std::cout << ' ' << *it;
		}
		std::cout << '\n';
	}
	return (0);
}

template <typename T>
bool	printMutantStack(const MutantStack<T> &mstack) {
	typename MutantStack<T>::const_iterator	it = mstack.begin();

	++it;
	--it;
	std::cout << "mstack: ";
	while (it != mstack.end()) {
		std::cout << *it << ' ';
		++it;
	}
	std::cout << '\n';
	return (true);
}