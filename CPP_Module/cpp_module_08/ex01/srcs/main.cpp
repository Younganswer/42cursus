#include "../incs/Span.hpp"
#include <iostream>

bool	testSpan(Span &span);

int	main(void) {
	{
		Span	span(5);

		try {
			span.addNumber(6);
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
		Span	span(5);

		try {
			span.addNumber(6);
			span.addNumber(3);
			span.addNumber(17);
			span.addNumber(9);
			span.addNumber(9);
			testSpan(span);
		} catch (std::exception &e) {
			std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		}
	}
	std::cout << '\n';
	{
		Span	span(5);

		try {
			span.addNumber(6);
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
		Span	span(5);

		try {
			span.addNumber(6);
			testSpan(span);
		} catch (std::exception &e) {
			std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		}
	}
	std::cout << '\n';
	{
		Span				span(5);
		std::vector<int>	vec;

		try {
			vec.push_back(6);
			vec.push_back(3);
			vec.push_back(17);
			vec.push_back(9);
			vec.push_back(11);
			span.insert(span.cbegin(), vec.begin(), vec.end());
			testSpan(span);
		} catch (std::exception &e) {
			std::cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << '\n';
		}
	}
	std::cout << '\n';
	{
		Span				span(5);
		std::vector<int>	vec;

		try {
			vec.push_back(6);
			vec.push_back(3);
			vec.push_back(17);
			vec.push_back(9);
			vec.push_back(11);
			vec.push_back(15);
			span.insert(span.cbegin(), vec.begin(), vec.end());
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
	std::cout << "Span: " << span << '\n';
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