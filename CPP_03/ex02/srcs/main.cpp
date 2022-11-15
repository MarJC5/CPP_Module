/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:21:25 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:21:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

static void	tic_tac(int usleep_time, int duration)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << "." << std::endl;
		usleep(usleep_time);
	}
}

int main(void)
{
	ScavTrap 	one("Jotaro");
	tic_tac(500000, 1);

	ClapTrap	two("polnareff");
	tic_tac(500000, 1);

	FragTrap 	three("Josuke");
	tic_tac(500000, 1);

	while (three.getEnergyPoints() > 0)
		three.attack("Dio");
	tic_tac(500000, 2);
	three.beRepaired(2);
	tic_tac(500000, 2);
	three.takeDamage(one.getAttackDamage());
	tic_tac(500000, 2);
	three.highFivesGuys();
	tic_tac(500000, 2);

	two.attack("Dio");
	tic_tac(500000, 2);
	two.beRepaired(2);
	tic_tac(500000, 2);

	one.attack("Dio");
	tic_tac(500000, 2);
	one.beRepaired(42);
	tic_tac(500000, 2);
	one.takeDamage(two.getAttackDamage());
	tic_tac(500000, 2);
	one.guardGate();
	tic_tac(500000, 2);
}