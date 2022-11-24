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
		Fixed(int const value); // constructor that takes an int as a parameter
		Fixed(float const value); // constructor that takes a float as a parameter
		Fixed( Fixed const &instance );
		virtual ~Fixed( void );

		Fixed &operator=( Fixed const &rhs );

		float   toFloat( void ) const;
		int     toInt( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
