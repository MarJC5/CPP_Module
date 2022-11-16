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
# include "Brain.hpp"

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &instance);
		virtual ~Animal(void); // virtual destructor to avoid memory leaks

		Animal &operator=(Animal const &rhs);

		std::string     getType() const;
		virtual void    makeSound() const; // virtual function to be able to override it in the derived classes
		virtual Brain   *getBrain() const = 0; // pure virtual function to be able to override it in the derived classes

	protected:
		std::string _type;
};

#endif
