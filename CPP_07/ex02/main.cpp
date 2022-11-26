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

#include "Array.hpp"
#define MAX_VAL 750

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
}