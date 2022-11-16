/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

static void	tic_tac(int usleep_time, int duration)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << "." << std::endl;
		usleep(usleep_time);
	}
}

int main(void) {

	{
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();
		const Animal *animal = new Animal();
		tic_tac(500000, 1);

		std::cout << "Type: " << dog->getType() << std::endl;
		dog->makeSound(); //will output the cat sound!
		tic_tac(500000, 2);

		std::cout << "Type: " << cat->getType() << std::endl;
		cat->makeSound(); //will output the dog sound!
		tic_tac(500000, 2);

		std::cout << "Type: " << animal->getType() << std::endl;
		animal->makeSound();
		tic_tac(500000, 1);


		delete dog;
		delete cat;
		delete animal;
	}
	{
		tic_tac(500000, 5);
		const WrongCat *cat = new WrongCat();
		const WrongAnimal *animal = new WrongAnimal();
		tic_tac(500000, 1);

		std::cout << "Type: " << cat->getType() << std::endl;
		cat->makeSound(); //will output the dog sound!
		tic_tac(500000, 2);

		std::cout << "Type: " << animal->getType() << std::endl;
		animal->makeSound();
		tic_tac(500000, 1);


		delete cat;
		delete animal;
	}

	return (0);
}