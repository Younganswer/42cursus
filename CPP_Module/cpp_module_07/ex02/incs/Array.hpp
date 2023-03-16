#ifndef ARRAY_HPP
# define ARRAY_HPP
# define ui unsigned int

# include <iostream>

template <typename T>
class Array {
	private:
		T	*_arr;
		ui	_size;
		ui	_max_size;

	public:
		Array(void);
		Array(ui n);
		Array(const Array<T> &ref);
		Array<T>	&operator=(const Array<T> &rhs);
		~Array(void);
		
		T	&operator[](ui idx) throw(std::exception);
		ui	size(void) const;

		// Exception: Out of range
		class OutOfRangeException: public std::exception {
			private:

			public:
				OutOfRangeException(void);
				OutOfRangeException(const OutOfRangeException &ref);
				OutOfRangeException	&operator=(const OutOfRangeException &rhs);
				virtual ~OutOfRangeException(void) throw();
				virtual const char *what(void) const throw();
		};
};

template <typename T>
Array<T>::Array(void): _arr(NULL), _size(0), _max_size(0) {}

template <typename T>
Array<T>::Array(ui n): _arr(new T[n]), _size(0), _max_size(n) {}

template <typename T>
Array<T>::Array(const Array<T> &ref) { *this = ref; }

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhs) {
	if (this != &rhs) {
		if (this->_arr) {
			delete [] this->_arr;
		}
		this->_arr = new T[rhs._max_size];
		this->_size = rhs._size;
		this->_max_size = rhs._max_size;
		for (ui i=0; i<this->_size; i++) {
			this->_arr[i] = rhs._arr[i];
		}
	}
		
	return (*this);
}

template <typename T>
Array<T>::~Array(void) {
	if (this->_arr) {
		delete [] this->_arr;
	}
}

template <typename T>
T	&Array<T>::operator[](ui idx) throw(std::exception) {
	if (idx < 0 || this->_size <= idx) {
		throw Array<T>::OutOfRangeException();
	}
	return (this->_arr[idx]);
}

template <typename T>
ui	Array<T>::size(void) const {
	return (this->_size);
}

// Exception: Out of range
template <typename T>
Array<T>::OutOfRangeException::OutOfRangeException(void) {}

template <typename T>
Array<T>::OutOfRangeException::OutOfRangeException(const OutOfRangeException &ref) { *this = ref; }

template <typename T>
typename Array<T>::OutOfRangeException	&Array<T>::OutOfRangeException::operator=(const OutOfRangeException &rhs) {
	(void) rhs;
	return (*this);
}

template <typename T>
Array<T>::OutOfRangeException::~OutOfRangeException(void) throw() {}

template <typename T>
const char	*Array<T>::OutOfRangeException::what(void) const throw() {
	return ("Out of range");
}

#endif