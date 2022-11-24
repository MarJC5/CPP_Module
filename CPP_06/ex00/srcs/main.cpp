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

#include "../inc/ScalarTypes.hpp"
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [args]" << std::endl;
		return (1);
	}
	ScalarTypes	convert(argv[1]);
	try {
		convert.display();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}