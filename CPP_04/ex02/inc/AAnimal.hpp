/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

// Colors
# define GREEN	"\033[1;32m"
# define RED 	"\033[1;31m"
# define ORANGE	"\033[1;33m"
# define CYAN	"\033[1;36m"
# define NC     "\033[0m"

# include <iostream>
# include <string>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(AAnimal const &instance);
		virtual ~AAnimal(void);

		AAnimal &operator=(AAnimal const &rhs);

		void			    setType(const std::string &type);
		const std::string	getType(void) const;

		/*
		 * pure virtual function (method = 0) is a function that is declared within a base class
		 * and is re-defined (Overriden) by a derived class
		 * /!\ A class that has at least one pure virtual function is called an abstract class
		 * /!\ An abstract class cannot be instantiated
		*/
		virtual void        makeSound(void) const = 0;

	protected:
		std::string _type;
};

#endif
