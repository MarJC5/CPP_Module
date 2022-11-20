/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:24 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

// Colors
# define GREEN	"\033[1;32m"
# define RED 	"\033[1;31m"
# define ORANGE	"\033[1;33m"
# define CYAN	"\033[1;36m"
# define GREY   "\033[1;37m"
# define NC     "\033[0m"

# include <iostream>
# include <string>
# include "ICharacter.hpp"

/*
 * AMateria is an abstract class, so it cannot be instantiated.
 * It is the base class for all the other classes.
 */
class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &instance);
		virtual ~AMateria(void); // virtual destructor to avoid memory leaks

		AMateria &operator=(AMateria const &rhs);

		std::string const &getType(void) const;

		/*
		 * virtual AMateria* clone(void) const = 0;
		 * is polymorphic, it will be implemented in the derived classes
		 * and will return a copy of the current instance
		 */
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string	    _type;
};

#endif