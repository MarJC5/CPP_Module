/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:18:43 by jmartin           #+#    #+#             */
/*   Updated: 2022/10/25 09:18:43 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::_fields[6] = {
	"INDEX",
	"FIRST NAME",
	"LAST NAME",
	"NICKNAME",
	"PHONE NUMBER",
	"DARKEST SECRET"
};

Contact::Contact() {
	this->_NbDetails = 6;
	for (int i = 0; i < this->_NbDetails; i++) {
		this->_details[i] = std::string();
	}
	return;
}

 Contact::~Contact(void) {
	return;
}

void    Contact::_fieldSeparator(int NbInfo) {
	for (int i = 0; i < (NbInfo * 11) + 1; i++)
		std::cout << C << "-" << NC;
	std::cout << std::endl;
}

void    Contact::showHeader(int NbInfo) {
	this->_fieldSeparator(NbInfo);
	for (int i = 0; i < NbInfo; i++) {
		std::cout << C << "|";
		if (this->_fields[i].length() > 10) {
			std::cout << this->_fields[i].substr(0, 9) << ".";
		} else {
			for (long unsigned int j = 0; j < 10 - this->_fields[i].length(); j++) {
				std::cout << " ";
			}
			std::cout << this->_fields[i];
		}
	}
	std::cout << "|" << NC << std::endl;
}

bool    Contact::setContact(int index) {
	std::string input;

	this->_index = index + 1;
	this->_details[0] = std::to_string(this->_index);
	std::cout << C << "# Please fill the following:" << NC << std::endl;
	for (int i = 1; i < this->_NbDetails; i++) {
		std::cout << "# " << this->_fields[i] << ":" << std::endl;
		std::cout << C << "> " << NC;
		std::getline(std::cin, this->_details[i]);
		if (this->_details[i].length() == 0) {
			std::cout << EC << "# Error: Empty field." << NC << std::endl;
			input.clear();
			while (input.length() == 0) {
				std::cout << "# Do you want to continue ? [y/n]: ";
				std::getline(std::cin, input);
				if (input == "y") {
					i--;
					break;
				} else if (input == "n") {
					std::cout << IC << "# Contact hasn't been added to phonebook.\n" << NC << std::endl;
					return (false);
				}
			}
		}
	}
	std::cout << SC << "# Contact n°" << this->_index << " added to phonebook.\n" << NC << std::endl;
	return (true);
}

void    Contact::showContact(int NbInfo) {
	this->_fieldSeparator(NbInfo);
	for (int i = 0; i < NbInfo; i++) {
		std::cout << C << "|" << NC;
		if (this->_details[i].length() > 10) {
			std::cout << this->_details[i].substr(0, 9) << ".";
		} else {
			for (long unsigned int j = 0; j < 10 - this->_details[i].length(); j++) {
				std::cout << " ";
			}
			std::cout << this->_details[i];
		}
	}
	std::cout << C << "|" << NC << std::endl;
}