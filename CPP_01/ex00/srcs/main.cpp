/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:20:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:16:50 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main( void ) {

	Zombie *zombiePTR = newZombie( std::string("Luffy") );
	zombiePTR->announce();

	// Free
	delete zombiePTR;

	std::cout << std::endl;
	Zombie zombie( std::string("Zoro") );
	zombie.announce();

	std::cout << std::endl;
	randomChump( std::string("Sanji") );

	return (0);
}