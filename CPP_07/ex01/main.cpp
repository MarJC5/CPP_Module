/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:24:21 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:24:21 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

void	print(int const &i)
{
	std::cout << i << std::endl;
}

void toUpper(std::string const &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			std::cout << (char)(str[i] - 32);
		else
			std::cout << str[i];
	}
}

int	main(void)
{
	{
		int		array[5] = {1, 2, 3, 4, 5};

		::iter<int>(array, 5, print);
	}
	{
		std::string		array[5] = {"hello ", "world ", "this ", "is ", "a test"};
		::iter<std::string>(array, 5, toUpper);
	}
	return (0);
}