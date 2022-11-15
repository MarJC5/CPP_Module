/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:21:44 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:21:45 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap // virtual inheritence to avoid diamond problem
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &instance);
		~ScavTrap(void);

		ScavTrap &operator=(ScavTrap const &rhs);

		void attack ( const std::string &target );
		void guardGate();

	protected: // static variables are initialized in the .cpp file
		static int hitPointsInit;
		static int energyPointsInit;
		static int attackDamageInit;
};

#endif