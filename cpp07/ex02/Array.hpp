/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:05:27 by mykle             #+#    #+#             */
/*   Updated: 2025/05/26 12:44:58 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <cstring>

template <typename T> class Array 
{
private:
	unsigned int _size;
	T* _array;

public:
	 Array();
	 ~Array();
	 Array(unsigned int n);
	 Array(const Array<T>& other);
	 Array<T>& operator=(const Array<T>& other);
	 T& operator[](unsigned int index);
	 const T& operator[](unsigned int index) const;
	 unsigned int size() const;
};

template <typename T> Array<T>::Array()
	: _size(0), _array(new T[0]()) {}

template <typename T> Array<T>::Array(unsigned int n)
	: _size(n), _array(new T[n]()) {}

template <typename T> Array<T>::Array(const Array<T> &origin)
	: _size(origin._size), _array(new T[origin._size]())
{
	memcpy(_array, origin._array, sizeof(T) * _size);
}

template <typename T> Array<T>::~Array()
{
	if (_array) delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		if (_array) delete[] _array;
		_size = other._size;
		_array = new T[_size];
		memcpy(_array, other._array, sizeof(T) * _size);
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}
