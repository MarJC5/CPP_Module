/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:24 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

/*
 * The Ice class is a child of the AMateria class.
 * It is used to create a new Ice Materia object.
 */
class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &instance);
		virtual ~Ice(void); // virtual destructor to avoid memory leaks

		Ice &operator=(Ice const &rhs);

		AMateria *clone(void) const;
};

#endif