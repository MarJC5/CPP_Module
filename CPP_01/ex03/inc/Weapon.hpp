/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:17:56 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:56 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>
# include "Weapon.h"

class Weapon {

	public:
		Weapon(std::string type);
		~Weapon( void );

		std::string const  &getType(void); // reference to type string, to avoid copy
		void               setType(std::string type);

	private:
		std::string        _type;
};

#endif