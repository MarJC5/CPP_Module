/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:18:47 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:18:48 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include "Harl.h"

class Harl {

	public:
		Harl();
		~Harl();

		void        complain( std::string level );

	private:
		void        _debug( void );
		void        _info( void );
		void        _warning( void );
		void        _error( void );
};

#endif