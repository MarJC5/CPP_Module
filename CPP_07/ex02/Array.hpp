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

template <typename T>
class Array
{
	public:
		Array<T>(void); // empty array
		Array<T>(unsigned int n);
		Array<T>(Array<T> const &src); // copy
		~Array<T>(void);

		Array<T> &	operator=(Array<T> const & rhs);

		T &	operator[](unsigned int i);

		unsigned int	size(void) const;

	private:
		T *	_array;
		unsigned int	_size;
};

/*
 * Array constructor with no arguments create empty array
 */
template <typename T>


/*
 * Construction with an unsigned int n as a parameter:
 * Creates an array of n elements initialized by default
 */
template <typename T>



#endif