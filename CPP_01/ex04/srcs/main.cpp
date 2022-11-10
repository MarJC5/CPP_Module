/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:18:16 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:18:17 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Replace.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Usage: ./ex04 [filename] [string] [string]" << std::endl;
		return (1);
	}

	Replace file(argv[1]); // create an object of type Replace with the filename as argument
	file.replace( std::string(argv[2]), std::string(argv[3])); // call the replace method of the object data with the two strings as arguments
	file.showDiff(); // call the showDiff method of the object data

	return (0);
}
