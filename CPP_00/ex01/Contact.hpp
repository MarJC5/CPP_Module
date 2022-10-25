/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:18:35 by jmartin           #+#    #+#             */
/*   Updated: 2022/10/25 09:18:35 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact {

	public:
		Contact();
		~Contact();

		bool       saveContact();
		void       showContact();
		static int getNbContact(void);

	private:
		static std::string  _fields[5];
		std::string         _details[5];
		static int          _NbContact;
		int                 _index;
		// User-defined data type
		enum _user {
			firstName,
			lastName,
			nickname,
			phoneNumber,
			darkestSecret
		};
};

#endif