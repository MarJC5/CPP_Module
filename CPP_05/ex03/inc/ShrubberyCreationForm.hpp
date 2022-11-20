/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:23:19 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:23:19 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <exception>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &instance);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

		virtual void			execute(Bureaucrat const &executor) const; // override
		std::string const		&getTarget(void) const;

		// Exceptions
		class FormFileNotOpenException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormFileWriteException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string				        _target;
		static const std::string		_tree;
};

#endif