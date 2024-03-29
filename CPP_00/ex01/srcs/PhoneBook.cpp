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

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_items = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void    PhoneBook::_printPhoneBook() {
	for (int i = 0; i < MAX_CONTACTS; ++i) {
		if (i == 0)
			this->_contacts[i].showHeader(4);
		this->_contacts[i].showContact(4);
	}
}

void    PhoneBook::addContact() {
	if (this->_items == MAX_CONTACTS) {
		this->_items = 0;
	}
	if (this->_contacts[this->_items].setContact(this->_items)) {
		this->_items++;
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
	this->_printPhoneBook();
	std::cout << C << "\n# Please enter the index of the contact you want to see:" << NC << std::endl;
	std::cout << C << "> " << NC;
	std::getline(std::cin, input);
	if (input.length() == 1 && input[0] >= '1' && input[0] <= '8') {
		index = input[0] - '0';
		if (index <= this->_items) {
			this->_contacts[index - 1].display();
		} else {
			std::cout << EC << "\nContact not found." << NC << std::endl;
		}
	} else {
		std::cout << EC << "\nInvalid index." << NC << std::endl;
	}
	return;
}