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

#include "../inc/DiamondTrap.hpp"

static void	tic_tac(int usleep_time, int duration)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << "↓" << std::endl;
		usleep(usleep_time);
	}
}

int main(void)
{
	DiamondTrap diamond("Giorno");
	tic_tac(500000, 1);

	std::cout << "---------------" << std::endl;
	std::cout << std::left << std::setw(15) << "Attack Damage" << ": " << diamond.getAttackDamage() << std::endl;
	std::cout << std::left << std::setw(15) << "Energy" << ": " << diamond.getEnergyPoints() << std::endl;
	std::cout << std::left << std::setw(15) << "Hit points" << ": " << diamond.getHitPoints() << std::endl;
	std::cout << "---------------" << std::endl;
	tic_tac(500000, 2);
	diamond.guardGate();
	tic_tac(500000, 2);
	diamond.whoAmI();
	tic_tac(500000, 2);
	diamond.attack("Dio");
	tic_tac(500000, 2);
	diamond.highFivesGuys();
	tic_tac(500000, 2);
	return (0);
}