/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:18:27 by jmartin           #+#    #+#             */
/*   Updated: 2022/10/25 09:18:27 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define ADD "ADD"
# define SEARCH "SEARCH"
# define EXIT "EXIT"
# define MAX_CONTACTS 8

# include <iostream>
# include <stdlib.h>
# include "format.h"
# include "Contact.hpp"

class PhoneBook {

	public:

		PhoneBook();
		~PhoneBook();

		void    addContact(void);
		void    searchContact(void);

	private:

		int     _items;
		Contact _contacts[8];

		void    _printPhoneBook(int NbInfo);
};

#endif
