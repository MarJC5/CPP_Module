/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:23:37 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:23:37 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>
# include <string>

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &instance);
		~Intern(void);

		Intern &operator=(Intern const &rhs);

		AForm  *makeForm(std::string const &name, std::string const &target);

		// Exceptions
		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		static const std::string	_formNames[3];
};

#endif