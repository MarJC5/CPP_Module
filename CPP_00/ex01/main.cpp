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

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook    phonebook;
	std::string  userLine;
	bool         isExit = false;

	while (!isExit)
	{
		std::cout << "> ";
		std::getline(std::cin, userLine);
		if (userLine == EXIT)
		{
			std::cout << EXIT << "\nsee you!" << std::endl;
			isExit = true;
		}
		if (userLine == ADD)
			phonebook.addContact();
		if (userLine == SEARCH)
			phonebook.searchContact();
	}
	return (0);
}