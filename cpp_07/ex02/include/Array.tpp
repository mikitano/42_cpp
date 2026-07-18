/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 19:30:52 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/17 23:20:47 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	if (n == 0)
		_data = NULL;
	else
		_data = new T[_size];
}

template <typename T>
Array<T>::Array(const Array& copy) : _size(copy._size) {
	this->_data = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = copy._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
	if (this != &rhs) {
		delete[] _data;
		_size = rhs._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = rhs._data[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}