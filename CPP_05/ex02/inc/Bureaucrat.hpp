/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:40 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/25 10:21:50 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define GREEN	"\033[1;32m"
# define RED 	"\033[1;31m"
# define ORANGE	"\033[1;33m"
# define CYAN	"\033[1;36m"
# define GREY   "\033[1;37m"
# define NC     "\033[0m"

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <exception>

class AForm; // Forward declaration of AForm class to avoid circular dependency

class Bureaucrat
{
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &instance);
		~Bureaucrat();

		Bureaucrat	&operator=(Bureaucrat const &rhs);

		std::string const	&getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm &form);
		void                executeForm(AForm const &form);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif