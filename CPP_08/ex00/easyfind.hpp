/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:24:43 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:24:44 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

/*
 * A vector is a sequence container that encapsulates dynamic size arrays.
 * Just like arrays, vectors use contiguous storage locations for their elements,
 * which means that their elements can also be accessed using offsets on regular
 * pointers to its elements, and just as efficiently as in arrays.
 *
 * But unlike arrays, their size can change dynamically, with their storage
 * being handled automatically by the container.
 *
 * Internally, vectors use a dynamically allocated array to store their elements.
 *
 * This array may need to be reallocated in order to grow in size when new
 * elements are inserted, which implies allocating a new array and moving all
 * elements to it. This is a relatively expensive task in terms of processing
 * time, and thus, vectors do not reallocate each time an element is added to
 * the container.
 */

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Value not found");
		}
};

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif