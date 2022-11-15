/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:01 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:02 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap // 2 parents
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &instance);
		~DiamondTrap(void);

		DiamondTrap &operator=(DiamondTrap const &rhs);

		void    attack(std::string const &target); // override
		void    whoAmI(void);

	private:
		std::string	_name; // name of the DiamondTrap
};

#endif