/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:20:39 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:06 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include "Zombie.h"

class Zombie {

	public:
		Zombie();
		~Zombie();

		Zombie(std::string name);

		void announce( void );
		void setName(std::string name);

	private:
		std::string _name;
};

Zombie*    zombieHorde( int N, std::string name );

#endif