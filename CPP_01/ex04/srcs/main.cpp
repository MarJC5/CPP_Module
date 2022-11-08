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

	std::string filename(argv[1]);
	std::ifstream ifs(filename);
	if (ifs.is_open()) {
		std::cout << ifs.rdbuf() << std::endl;
		ifs.close();
		std::cout << std::endl;
	} else {
		std::cout << "Unable to open file" << std::endl;
		return (1);
	}

	Replace file(argv[1]); // create an object of type Replace with the filename as argument
	file.replace(argv[2], argv[3]); // call the replace method of the object data with the two strings as arguments

	// display file content after replacement
	std::ifstream ifsReplace(filename + ".replace");
	if (ifsReplace.is_open()) {
		std::cout << CYAN << std::endl;
		std::cout << ifsReplace.rdbuf() << NC << std::endl;
		ifsReplace.close();
	} else {
		std::cout << "Unable to open file" << std::endl;
		return (1);
	}

	return (0);
}
