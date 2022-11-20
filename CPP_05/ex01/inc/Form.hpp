/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:53 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:53 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration of Bureaucrat class to avoid circular dependency

class Form
{
	public:
		Form(std::string const name, int const gradeToSign, int const gradeToExecute);
		Form(Form const &instance);
		~Form(void);

		Form &operator=(Form const &rhs);

		std::string const &getName(void) const;

		bool    getSigned(void) const;
		int     getGradeToSign(void) const;
		int     getGradeToExecute(void) const;
		void    beSigned(Bureaucrat const &bureaucrat);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif