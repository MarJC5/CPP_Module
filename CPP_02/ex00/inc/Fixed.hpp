/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:19:38 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:19:38 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

// Colors
# define GREEN	"\033[1;32m"
# define RED 	"\033[1;31m"
# define ORANGE	"\033[1;33m"
# define CYAN	"\033[1;36m"
# define NC     "\033[0m"

// Libs
# include <iostream>
# include <string>
# include <unistd.h>

/*
 * Fixed( Fixed const &instance );
	* Copy constructor (constructor that takes an object of the same class as a parameter)
	* When shall we use it?
	* 1. When we want to create a new object based on an existing object of the same class
	* 2. When we want to pass an object of the class to a function by value
	* 4. When we want to initialize an object of the class in the declaration
*/

/*
 * Fixed &operator=( Fixed const &rhs );
	*  The assignment operator is a member function
	*  that takes a reference to an object of the same class as a parameter
	*  and returns a reference to the current object
	*
	*  In summary, the assignment operator is used to assign
	*  a new value to an object that already exists
*/

/*
 * std::ostream &operator<<(std::ostream &o, Fixed const &rhs);
    * Non-member function overload (<<) to print the value of the Fixed point number (<< is the insertion operator)
    * We use a reference to a constant object of type Fixed to avoid modifying the object
    * and to avoid making a copy of the object
 */

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const &instance );
		virtual ~Fixed( void );

		Fixed &operator=( Fixed const &rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
