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

# include <iostream>
# include <string>

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

	protected:
		std::string _type;
};

#endif
