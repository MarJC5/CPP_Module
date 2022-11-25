/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:24:29 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:24:30 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const & src);
		~Array<T>(void);
		Array<T> &	operator=(Array<T> const & rhs);
		T &	operator[](unsigned int i);
		unsigned int	size(void) const;

	private:
		T *	_array;
		unsigned int	_size;
};

template <typename T>
Array<T>::Array(void) : _array(new T[0]), _size(0)
{
	return ;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	return ;
}

template <typename T>


#endif