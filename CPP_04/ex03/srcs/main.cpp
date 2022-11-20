/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:24 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IMateriaSource.hpp"
#include "../inc/MateriaSource.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include <unistd.h>

static void	tic_tac(int usleep_time, int duration, std::string color)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << color << "↓" << NC << std::endl;
		usleep(usleep_time);
	}
}

int main(void) {
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice()); // learn ice
		src->learnMateria(new Cure()); // learn cure
		tic_tac(500000, 2, ORANGE);

		ICharacter *me = new Character("me"); // create character
		ICharacter *bob = new Character("bob"); // create character
		tic_tac(500000, 2, ORANGE);

		AMateria *tmp;
		tmp = src->createMateria("ice"); // create ice
		me->equip(tmp); // equip ice
		tic_tac(500000, 1, ORANGE);
		tmp = src->createMateria("cure"); // create cure
		me->equip(tmp); // equip cure
		tic_tac(500000, 2, ORANGE);

		me->use(0, *bob); // use ice
		me->use(1, *bob); // use cure
		tic_tac(500000, 2, ORANGE);

		me->unequip(0); // unequip ice
		tic_tac(500000, 1, ORANGE);
		me->unequip(1); // unequip cure
		tic_tac(500000, 2, ORANGE);

		delete src;
		delete me;
		delete bob;
	}

	return (0);
}