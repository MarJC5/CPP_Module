/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:24 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

/*
 * The Cure class is a child of the AMateria class.
 * It is used to create a new Cure object.
 */
class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &instance);
		virtual ~Cure(void); // virtual destructor to avoid memory leaks

		Cure &operator=(Cure const &rhs);

		AMateria *clone(void) const;
};

#endif