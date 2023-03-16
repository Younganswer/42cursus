#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack(void): std::stack<T>() {}
		MutantStack(const MutantStack &ref): std::stack<T>(ref) {}
		MutantStack	&operator=(const MutantStack &rhs) {
			if (this != &rhs) {
				std::stack<T>::operator=(rhs);
			}
			return (*this);
		}
		~MutantStack(void) {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin(void) {
			return (std::stack<T>::c.begin());
		}
		
		iterator	end(void) {
			return (std::stack<T>::c.end());
		}
};

#endif