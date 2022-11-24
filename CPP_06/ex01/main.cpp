/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:42 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <unistd.h>

static void	tic_tac(int usleep_time, int duration, std::string color)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << color << " " << NC << std::endl;
		usleep(usleep_time);
	}
}

int main(void)
{
	Data        *data = new Data();
	Data        *data2;
	uintptr_t   raw;

	std::cout << ORANGE << "----- Original data: -----" << NC << std::endl;
	data->setValue("Hello World!"); // set value
	std::cout << "Value: " << data->getValue() << std::endl; // get value
	tic_tac(100000, 2, ORANGE);

	std::cout << ORANGE << "----- Serialize data: -----" << NC << std::endl;
	raw = serialize(data); // save as uintptr_t as it's a pointer to a void *
	std::cout << "Raw: " << raw << std::endl;
	tic_tac(100000, 2, ORANGE);

	std::cout << ORANGE << "----- Deserialize data: -----" << NC << std::endl;
	data2 = deserialize(raw); // cast back to Data * to use it as a Data * again
	std::cout << "Value: " << data2->getValue() << std::endl;
	tic_tac(100000, 2, ORANGE);

	std::cout << GREEN << "----- Compare data: -----" << NC << std::endl;
	std::cout << "data->getValue(): "
	          << data->getValue()
	          << std::endl;
	std::cout << "data2->getValue(): "
	          << data2->getValue()
	          << std::endl;

	delete data;

	return (0);
}