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

#include "../inc/ClapTrap.hpp"

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
	ClapTrap	nameless;
	tic_tac(500000, 1);

	ClapTrap	one("Jotaro");
	tic_tac(500000, 1);

	ClapTrap	two("polnareff");
	tic_tac(500000, 1);

	ClapTrap	duplicated(one);
	tic_tac(500000, 1);

	while (one.getEnergyPoints() > 0)
		one.attack("Dio");
	tic_tac(500000, 2);
	one.beRepaired(2);
	tic_tac(500000, 2);
	one.takeDamage(17);
	tic_tac(500000, 2);

	two.attack("Dio");
	tic_tac(500000, 2);

	two.beRepaired(2);
	tic_tac(500000, 2);
}