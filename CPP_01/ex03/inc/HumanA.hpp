/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:17:27 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:27 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "HumanA.h"
# include "Weapon.hpp"

class HumanA {

	public:
		HumanA( std::string name, Weapon &weapon ); // reference to Weapon (pointer) initilized in constructor
		~HumanA( void );

		void	    attack( void );

	private:
		std::string	_name;
		Weapon		_weapon;
};

#endif