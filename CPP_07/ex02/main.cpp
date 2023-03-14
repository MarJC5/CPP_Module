/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:24:31 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:24:32 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "Array.hpp"

int	main(void)
{
	{
		Array<int>		arrayInt(5);
		Array<float>	arrayFloat(5);
		Array<std::string>	arrayString(5);

		for (int i = 0; i < 5; i++)
		{
			arrayInt[i] = i;
			arrayFloat[i] = i + 0.5;
			arrayString[i] = "Hello";
		}
		for (int i = 0; i < 5; i++)
		{
			std::cout << "arrayInt[" << i << "] = " << arrayInt[i] << std::endl;
			std::cout << "arrayFloat[" << i << "] = " << arrayFloat[i] << std::endl;
			std::cout << "arrayString[" << i << "] = " << arrayString[i] << std::endl;
			std::cout << std::endl;
		}

		// Get the size of the array
		std::cout << "arrayInt[size] = " << arrayInt.size() << std::endl;
		std::cout << "arrayFloat[size] = " << arrayFloat.size() << std::endl;
		std::cout << "arrayString[size] = " << arrayString.size() << std::endl;
		std::cout << std::endl;

		// Error handling for out of range
		try {
			std::cout << arrayInt[6] << std::endl;
		}
		catch (std::exception & e) {
			std::cout << "arrayInt[6] = " << e.what() << std::endl;
		}
	}
	return (0);
}*/

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "test 1" << '\n';
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "test 2" << '\n';
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}