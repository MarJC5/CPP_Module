/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:24 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class AMateria; // forward declaration to avoid circular dependencies between ICharacter.hpp and AMateria.hpp

/*
 * The ICharacter interface is the base class for all characters in the game.
 * It defines the basic methods that a character must implement.
 */
class ICharacter
{
	public:
		virtual ~ICharacter(void) {} // virtual destructor to avoid memory leaks
		virtual std::string const &getName(void) const = 0;
		virtual void	equip(AMateria *m) = 0; // equip Materia on the character
		virtual void	unequip(int idx) = 0; // unequip Materia on the character
		virtual void	use(int idx, ICharacter &target) = 0; // use Materia on the character
};

#endif