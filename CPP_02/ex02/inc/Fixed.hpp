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
# include <cmath>

class Fixed
{
	public:
		Fixed( void );
		Fixed(int const value);
		Fixed(float const value);
		Fixed( Fixed const &instance );
		~Fixed( void );

		Fixed &operator=( Fixed const &rhs );

		Fixed &operator++( void ); // pre-increment
		Fixed operator++( int ); // post-increment

		Fixed &operator--( void ); // pre-decrement
		Fixed operator--( int ); // post-decrement

		/*
		 * Wy const? because we don't want to modify
		 * the object itself (only the value)
		 */
		Fixed operator+( Fixed const &rhs ) const;
		Fixed operator-( Fixed const &rhs ) const;
		Fixed operator*( Fixed const &rhs ) const;
		Fixed operator/( Fixed const &rhs ) const;

		bool operator>( Fixed const &rhs ) const; // greater than
		bool operator<( Fixed const &rhs ) const; // less than
		bool operator>=( Fixed const &rhs ) const; // greater than or equal to
		bool operator<=( Fixed const &rhs ) const; // less than or equal to
		bool operator==( Fixed const &rhs ) const; // equal to
		bool operator!=( Fixed const &rhs ) const; // not equal to

		float   toFloat( void ) const;
		int     toInt( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		/*
		 * why &? because we want to modify the object (static member)
		 * and not a copy of it
		 */
		static  Fixed &min(Fixed &a, Fixed &b);
		static  Fixed &max(Fixed &a, Fixed &b);
		static  Fixed const &min(Fixed const &a, Fixed const &b);
		static  Fixed const &max(Fixed const &a, Fixed const &b);

	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
