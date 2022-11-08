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
		Weapon();
		Weapon(std::string type);

		~Weapon();

		std::string        getType(void);
		void               setType(std::string typePTR);

	private:
		std::string        _type;
};

#endif