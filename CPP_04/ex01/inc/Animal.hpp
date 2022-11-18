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

class Animal
{
	public:
		Animal(void); // Default constructor
		Animal(Animal const &instance); // copy constructor to avoid shallow copy of pointers in derived classes
		virtual ~Animal(void); // virtual destructor to avoid memory leaks

		Animal &operator=(Animal const &rhs); // virtual assignment operator to avoid memory leaks

		void			    setType(const std::string &type); // setter for type attribute
		const std::string	getType(void) const; // const to avoid changing the value of the attribute
		virtual void        makeSound(void) const; // virtual function to be able to override it in the derived classes

	protected:
		std::string _type; // protected attribute to be able to access it in the derived classes
};

#endif
