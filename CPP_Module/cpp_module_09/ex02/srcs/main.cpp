#include "Converter.hpp"
#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <deque>

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << " <num1> [num2] [num3] [...]" << '\n';
		return (1);
	}

	try {
		{
			std::vector<int>	vector;
			struct timeval		start, end;
			long				elapsed;

			for (int i=1; i<argc; i++) {
				vector.push_back(Converter::convert(argv[i]));
			}
			std::cout << "Vector before sorted: ";
			for (std::vector<int>::const_iterator it=vector.begin(); it!=vector.end(); it++) {
				std::cout << *it << ' ';
			}
			std::cout << std::endl;
			gettimeofday(&start, NULL);
			PmergeMe::sort(vector.begin(), vector.end());
			gettimeofday(&end, NULL);
			elapsed = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
			std::cout << "Vector after sorted: ";
			for (std::vector<int>::const_iterator it=vector.begin(); it!=vector.end(); it++) {
				std::cout << *it << ' ';
			}
			std::cout << std::endl;
			std::cout << "Time to process a range of " << vector.size() << " elements with std::vector<int>: " << elapsed << "us" << std::endl;
		}
		std::cout << std::endl;
		{
			std::deque<int>	deque;
			struct timeval	start, end;
			long			elapsed;
			
			for (int i=1; i<argc; i++) {
				deque.push_back(Converter::convert(argv[i]));
			}
			std::cout << "Deque before sorted: ";
			for (std::deque<int>::const_iterator it=deque.begin(); it!=deque.end(); it++) {
				std::cout << *it << ' ';
			}
			std::cout << std::endl;
			gettimeofday(&start, NULL);
			PmergeMe::sort(deque.begin(), deque.end());
			gettimeofday(&end, NULL);
			elapsed = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
			std::cout << "Deque after sorted: ";
			for (std::deque<int>::const_iterator it=deque.begin(); it!=deque.end(); it++) {
				std::cout << *it << ' ';
			}
			std::cout << std::endl;
			std::cout << "Time to process a range of " << deque.size() << " elements with std::deque<int>: " << elapsed << "us" << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}