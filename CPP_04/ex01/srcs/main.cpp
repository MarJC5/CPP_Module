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
#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

#define N 4

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
		const Animal *dog = new Dog();
		tic_tac(500000, 2, GREEN);
		const Animal *cat = new Cat();
		tic_tac(500000, 2, GREEN);
		delete dog;
		tic_tac(500000, 2, GREEN);
		delete cat;
		tic_tac(500000, 5, GREEN);
	}
	{
		// Stack allocation
		Dog dog;
		tic_tac(500000, 2, RED);
		Cat cat;
		tic_tac(500000, 2, RED);
		Cat cat2(cat); // Copy constructor
		tic_tac(500000, 5, RED);
	}
	{
		// Array of pointers to Animal
		Animal *animals[N];
		for (int i = 0; i < N; i++) {
			tic_tac(500000, 2, CYAN);
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for (int i = 0; i < N; i++) {
			tic_tac(500000, 2, CYAN);
			animals[i]->makeSound();
			tic_tac(500000, 2, CYAN);
			delete animals[i];
		}
	}
	return (0);
}