/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:42 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# define GREEN	"\033[1;32m"
# define RED 	"\033[1;31m"
# define ORANGE	"\033[1;33m"
# define CYAN	"\033[1;36m"
# define GREY   "\033[1;37m"
# define NC     "\033[0m"

# include <iostream>
# include <string>

/*
 * Serialization is the process of translating data structures
 * or object state into a format that can be stored
 * (for example, in a file or memory buffer, or transmitted across a network connection link)
 * and reconstructed later in the same or another computer environment.
 *
 * The opposite process is called deserialization.
 */

class Data
{
	public:
		Data(void);
		Data(Data const &instance);
		~Data(void);

		Data &	operator=(Data const & rhs);

		std::string		getValue(void) const;
		void			setValue(std::string value);

	private:
		std::string		_value;
};

uintptr_t	serialize(Data* ptr); // serialize the data
Data        *deserialize(uintptr_t raw); // return a pointer to a Data instance

#endif