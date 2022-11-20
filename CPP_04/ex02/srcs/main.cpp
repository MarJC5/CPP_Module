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
#include "../inc/AAnimal.hpp"
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
		// Heap allocation
		const AAnimal *dog = new Dog();
		tic_tac(500000, 1, GREEN);
		dog->makeSound();
		tic_tac(500000, 2, GREEN);
		const AAnimal *cat = new Cat();
		tic_tac(500000, 1, GREEN);
		cat->makeSound();
		tic_tac(500000, 2, GREEN);
		delete dog;
		tic_tac(500000, 2, GREEN);
		delete cat;
	}
	{
		/*
		 * Error: cannot instantiate abstract class 'Animal'
		 * An instance of an abstract class cannot be created directly
		 * it can only be created through a derived class ex: Animal *a = new Dog();
		*/

		/*
			AAnimal *animal = new Animal();
		    tic_tac(500000, 1, GREEN);
			animal->makeSound();
			tic_tac(500000, 2, RED);
			delete animal;
		*/
	}
	return (0);
}