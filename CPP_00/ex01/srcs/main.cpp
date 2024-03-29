/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:18:59 by jmartin           #+#    #+#             */
/*   Updated: 2022/10/25 09:18:59 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int main(void)
{
	PhoneBook    phonebook;
	std::string  userLine;
	bool         isExit = false;

	while (!isExit)
	{
		std::cout << C << "> " << NC;
		std::getline(std::cin, userLine);
		std::system("clear");
		if (userLine == EXIT) {
			std::cout << EXIT << std::endl << "see you!" << std::endl;
			isExit = true;
		} else if (userLine == ADD) {
			phonebook.addContact();
		} else if (userLine == SEARCH) {
			phonebook.searchContact();
		} else {
			std::cout << IC << "Please use one of the following commands:" << NC << std::endl;
			std::cout << ADD << std::endl << SEARCH << std::endl << EXIT << std::endl;
		}
	}
	return (0);
}