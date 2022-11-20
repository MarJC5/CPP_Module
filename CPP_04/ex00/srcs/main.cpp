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
		const Animal *dog = new Dog();
		tic_tac(500000, 1, GREEN);
		const Animal *cat = new Cat();
		tic_tac(500000, 1, GREEN);
		const Animal *animal = new Animal();
		tic_tac(500000, 1, GREEN);

		std::cout << "Type: " << dog->getType() << std::endl;
		dog->makeSound(); //will output the cat sound!
		tic_tac(500000, 2, GREEN);

		std::cout << "Type: " << cat->getType() << std::endl;
		cat->makeSound(); //will output the dog sound!
		tic_tac(500000, 2, GREEN);

		std::cout << "Type: " << animal->getType() << std::endl;
		animal->makeSound();
		tic_tac(500000, 2, GREEN);


		delete dog;
		tic_tac(500000, 1, GREEN);
		delete cat;
		tic_tac(500000, 1, GREEN);
		delete animal;
	}
	{
		tic_tac(500000, 5, RED);
		const WrongCat *cat = new WrongCat();
		tic_tac(500000, 1, RED);
		const WrongAnimal *animal = new WrongAnimal();
		tic_tac(500000, 1, RED);

		std::cout << "Type: " << cat->getType() << std::endl;
		cat->makeSound(); //will output the dog sound!
		tic_tac(500000, 2, RED);

		std::cout << "Type: " << animal->getType() << std::endl;
		animal->makeSound();
		tic_tac(500000, 2, RED);


		delete cat;
		tic_tac(500000, 1, RED);
		delete animal;
	}

	return (0);
}