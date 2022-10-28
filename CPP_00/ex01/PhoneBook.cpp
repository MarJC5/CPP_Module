/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:18:14 by jmartin           #+#    #+#             */
/*   Updated: 2022/10/25 09:18:14 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_items = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void    PhoneBook::_printPhoneBook(int NbInfo) {
	int	 amout = 0;

	if (this->_items >= MAX_CONTACTS) {
		amout = MAX_CONTACTS;
	} else {
		amout = this->_items;
	}
	for (int i = 0; i < amout; ++i) {
		if (i == 0)
			this->_contacts[i].showHeader(NbInfo);
		this->_contacts[i].showContact(NbInfo);
	}
}

void    PhoneBook::addContact() {
	if (this->_items >= MAX_CONTACTS) {
		for (int i = 0; i < MAX_CONTACTS - 1; ++i) {
			this->_contacts[i] = this->_contacts[i + 1];
		}
		if (this->_contacts[MAX_CONTACTS - 1].setContact(this->_items)) {
			this->_items++;
		}
	}
	else {
		if (this->_contacts[this->_items].setContact(this->_items)) {
			this->_items++;
		}
	}
	return;
}

void    PhoneBook::searchContact() {
	int         index;
	std::string input;

	if (this->_items == 0) {
		std::cout << IC << "Phonebook is empty, please use " << NC << ADD << std::endl;
		return;
	}
	this->_printPhoneBook(4);
	std::cout << C << "\n# Please enter the index of the contact you want to see:" << NC << std::endl;
	std::cout << C << "> " << NC;
	std::getline(std::cin, input);
	for(long unsigned i = 0 ; i < input.length();i++){
		if (input[i] < '0' || input[i] > '9'){
			std::cout << EC << "\nInvalid index." << NC << std::endl;
			return;
		}
	}
	if (input.length() > 0) {
		index = std::stoi(input);
		if (index >= 1 && index <= this->_items) {
			if (index <= this->_items) {
				this->_contacts[index - 1].showHeader(6);
				this->_contacts[index - 1].showContact(6);
			} else {
				std::cout << EC << "\nContact not found." << NC << std::endl;
			}
		} else {
			std::cout << EC << "\nInvalid index." << NC << std::endl;
		}
	} else {
		std::cout << EC << "\nInvalid index." << NC << std::endl;
	}
	return;
}