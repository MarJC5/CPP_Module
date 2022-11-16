/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const &instance);
		~Brain(void);

		Brain &operator=(Brain const &rhs);

		void        printIdeas(void) const;
		void        setIdea(int i, std::string idea);
		std::string getIdea(int i) const;

	private:
		std::string	_ideas[100];
};

#endif
