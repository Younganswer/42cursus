/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:30:26 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/18 15:38:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# define ui unsigned int

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
};

template <typename T>
Array<T>::Array(void): _arr(NULL), _size(0), _max_size(0) {}

template <typename T>
Array<T>::Array(ui n): _arr(new T[n]), _size(n), _max_size(n) {}

template <typename T>
Array<T>::Array(const Array<T> &ref) {
	*this = ref;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhs) {
	if (this == &rhs)
		return (*this);
		
	if (this->_arr)
		delete [] this->_arr;
		
	this->_arr = new T[rhs._size];
	this->_size = rhs._size;
	this->_max_size = rhs._max_size;
	for (ui i=0; i<this->_size; i++)
		this->_arr[i] = rhs._arr[i];
		
	return (*this);
}

template <typename T>
Array<T>::~Array(void) {
	if (this->_arr)
		delete [] this->_arr;
}

template <typename T>
T	&Array<T>::operator[](ui idx) throw(std::exception) {
	if (idx < 0 || this->_size <= idx)
		throw std::exception();
	return (this->_arr[idx]);
}

template <typename T>
ui	Array<T>::size(void) const {
	return (this->_size);
}

#endif