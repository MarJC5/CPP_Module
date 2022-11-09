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

#include "../inc/Contact.hpp"

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
	if (!this->_fields[0].empty()) {
		this->_fieldSeparator(NbInfo);
		for (int i = 0; i < NbInfo; i++) {
			std::cout << C << "|";
			if (this->_fields[i].length() > 10) {
				std::cout << this->_fields[i].substr(0, 9) << ".";
			} else {
				std::cout << std::right << std::setw(10) << this->_fields[i];
			}
		}
		std::cout << "|" << NC << std::endl;
		this->_fieldSeparator(NbInfo);
	}
}

bool    Contact::setContact(int index) {
	this->_index = index + 1;
	this->_details[0] = std::to_string(this->_index);
	std::cout << C << "# Please fill the following:" << NC << std::endl;
	for (int i = 1; i < this->_NbDetails; i++) {
		if (!this->_details[i].empty())
			this->_details[i].clear();
		while (this->_details[i].empty()) {
			std::cout << "# " << this->_fields[i] << ":" << std::endl;
			std::cout << C << "> " << NC;
			std::getline(std::cin, this->_details[i]);
			if (this->_details[i].empty()) {
				std::cout << EC << "# Error: Empty field." << NC << std::endl;
			}
		}
	}
	std::cout << SC << "# Contact n°" << this->_index << " added to phonebook.\n" << NC << std::endl;
	return (true);
}

void    Contact::showContact(int NbInfo) {
	if (!this->_details[0].empty()) {
		for (int i = 0; i < NbInfo; i++) {
			std::cout << C << "|" << NC;
			if (this->_details[i].length() > 10) {
				std::cout << this->_details[i].substr(0, 9) << ".";
			} else {
				std::cout << std::right << std::setw(10) << this->_details[i];
			}
		}
		std::cout << C << "|" << NC << std::endl;
		this->_fieldSeparator(NbInfo);
	}
}

void   Contact::display(void) {
	if (!this->_details[0].empty()) {
		for (int i = 0; i < this->_NbDetails; i++) {
			std::cout << C << "| ";
			std::cout << std::left << std::setw(15) << this->_fields[i];
			std::cout << C << "| " << NC;
			std::cout << this->_details[i] << std::endl;
		}
	}
}