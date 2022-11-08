/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:20:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/10/28 15:20:43 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie* newZombie(std::string name);

	Zombie *zombiePTR = newZombie(std::string("Luffy"));
	zombiePTR->announce();

	// Free
	delete zombiePTR;

	std::cout << std::endl;
	Zombie zombie(std::string("Zoro"));
	zombie.announce();

	std::cout << std::endl;
	randomChump(std::string("Sanji"));

	return (0);
}