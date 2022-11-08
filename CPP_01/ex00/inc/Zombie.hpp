/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:20:39 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:16:59 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include "Zombie.h"

class Zombie {

	public:
		Zombie( std::string name );
		~Zombie( void );

		void        announce( void );

	private:
		std::string _name;
};

Zombie* newZombie( std::string name );

#endif