#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack(void);
		MutantStack(const MutantStack &ref);
		virtual ~MutantStack(void);
		virtual MutantStack	&operator=(const MutantStack &rhs);

		// Utils
		virtual typename MutantStack<T>::iterator	begin(void) const;
		virtual typename MutantStack<T>::iterator	end(void) const;
};

template <typename T>
MutantStack<T>::MutantStack(void) {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &ref): std::stack<T>(ref) {}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &rhs) {
	if (this != &rhs) {
		this->~MutantStack();
		new (this) MutantStack(rhs);
	}
	return (*this);
}

// Utils
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) const { return (this->c.begin()); }

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) const { return (this->c.end()); }

#endif