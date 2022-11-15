/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:21:52 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:21:53 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"

class FragTrap: public virtual ClapTrap // virtual inheritence to avoid diamond problem
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &instance);
		~FragTrap(void);

		FragTrap &operator=(FragTrap const &rhs);

		void highFivesGuys();

	protected: // static variables are initialized in the .cpp file
		static int hitPointsInit;
		static int energyPointsInit;
		static int attackDamageInit;
};

#endif