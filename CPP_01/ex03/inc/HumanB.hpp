/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:17:37 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:38 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "HumanB.h"
# include "Weapon.hpp"

class HumanB {

	public:
		HumanB( std::string name );
		~HumanB( void );

		void	    attack( void );
		void	    setWeapon( Weapon &weapon );

	private:
		std::string	_name;
		Weapon		*_weapon; // reference to Weapon (pointer), will be initialized to NULL in constructor
};

#endif