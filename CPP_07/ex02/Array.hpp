/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:24:29 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/25 19:37:54 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

/*
 * A template class is a class that can be used with different types of data.
 *
 * To be able to use a template class, we need to define the type of data that will be used with the class.
 * eg:
 *  - Array<int> myArray; // myArray is an array of integers
 *  - Array<std::string> myArray; // myArray is an array of strings
 *
 */

template <typename T>
class Array
{
	public:
		/* CONSTRUCTORS */
		Array<T>(void) : _size(0) {
			this->_array = new T[this->_size];
		}

		Array<T>(unsigned int n) : _size(n) {
			this->_array = new T[this->_size];
		}

		/* COPY CONSTRUCTOR */
		Array<T>(Array<T> const &src) : _size(src.size()){
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}

		/* DESTRUCTORS */
		~Array<T>(void) {
			if (this->_array)
				delete [] this->_array;
		}

		/* OPERATORS */
		T &operator[](unsigned int i) {
			if (i >= this->_size || this->_array == NULL)
				throw Array<T>::InvalidIndexException();
			return (this->_array[i]);
		}

		Array<T> &operator=(Array<T> const &rhs) {
			if (this != &rhs)
			{
				if (this->_array != NULL)
					delete [] this->_array;
				this->_size = rhs.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = rhs._array[i];
			}
			return (*this);
		}

		/* GETTERS / SETTERS */
		unsigned int	size(void) const {
			return (this->_size);
		}

		/* EXCEPTIONS */
		class InvalidIndexException : public std::exception
		{
			public:
				virtual const char *	what(void) const throw() {
					return ("Error: Invalid index");
				}
		};

	private:
		T               *_array;
		unsigned int	_size;
};

#endif