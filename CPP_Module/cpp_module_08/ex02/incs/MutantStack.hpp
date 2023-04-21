#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	
	public:
		MutantStack(void);
		MutantStack(const MutantStack &ref);
		virtual ~MutantStack(void);
		virtual MutantStack	&operator=(const MutantStack &rhs);

		iterator		begin(void);
		iterator		end(void);
		const_iterator	begin(void) const;
		const_iterator	end(void) const;
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

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::begin(void) { return (this->c.begin()); }

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::end(void) { return (this->c.end()); }

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const { return (this->c.begin()); }

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const { return (this->c.end()); }

#endif