#include "../incs/Span.hpp"
#include <iostream>

bool	testSpan(Span &span);

int	main(void) {
	{
		Span	span = Span(5);

		try {
			span.addNumber(5);
			span.addNumber(3);
			span.addNumber(17);
			span.addNumber(9);
			span.addNumber(11);
			testSpan(span);
		} catch (std::exception &e) {
			std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		}
	}
	std::cout << '\n';
	{
		Span	span = Span(5);

		try {
			span.addNumber(5);
			span.addNumber(3);
			span.addNumber(17);
			span.addNumber(11);
			span.addNumber(11);
			testSpan(span);
		} catch (std::exception &e) {
			std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		}
	}
	std::cout << '\n';
	{
		Span	span = Span(5);

		try {
			span.addNumber(5);
			span.addNumber(3);
			span.addNumber(17);
			span.addNumber(9);
			span.addNumber(11);
			span.addNumber(15);
			testSpan(span);
		} catch (std::exception &e) {
			std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		}
	}
	std::cout << '\n';
	{
		Span	span = Span(5);

		try {
			span.addNumber(5);
			testSpan(span);
		} catch (std::exception &e) {
			std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		}
	}
	return (0);
}

bool	testSpan(Span &span) {
	std::cout << "Max size of span: " << span.maxSize() << '\n';
	std::cout << "Current size of span: " << span.size() << '\n';
	std::cout << "Span: ";
	span.print();
	try {
		int	shortest = span.shortestSpan();

		std::cout << "Shortest Span: " << shortest << '\n';
	} catch (std::exception &e) {
		std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		return (false);
	}
	try {
		int	longest = span.longestSpan();

		std::cout << "Longest Span: " << longest << '\n';
	} catch (std::exception &e) {
		std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		return (false);
	}
	return (true);
}