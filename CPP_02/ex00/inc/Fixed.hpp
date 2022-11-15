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

# include <iostream>
# include <string>
# include "Fixed.h"

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const &instance ); // Copy constructor
		~Fixed( void );

		Fixed &operator=( Fixed const &rhs ); // Assignation operator overload (can be a member function, but not a member)

		int		getRawBits( void ) const; // Return the raw value of the fixed point value
		void	setRawBits( int const raw ); // Set the raw value of the fixed point value

	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream &operator << ( std::ostream &o, Fixed const &rhs );

#endif
