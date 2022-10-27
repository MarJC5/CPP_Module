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
# include <string>
# include "format.h"

class Contact {

	public:
		Contact();
		~Contact();

		bool                setContact(int index);
		void                showContact(int NbInfo);
		void                showHeader(int NbInfo);

	private:
		static std::string  _fields[6];
		std::string         _details[6];
		int                 _index;
		int				    _NbDetails;

		void    		    _fieldSeparator(int NbInfo);
};

#endif