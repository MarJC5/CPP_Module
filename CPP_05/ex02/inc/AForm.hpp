/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:53 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:53 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat; // Forward declaration of Bureaucrat class to avoid circular dependency

class AForm
{
	public:
		AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
		AForm(AForm const &instance);
		~AForm(void);

		AForm &operator=(AForm const &rhs);

		std::string const &getName(void) const;

		bool    getSigned(void) const;
		int     getGradeToSign(void) const;
		int     getGradeToExecute(void) const;
		void    beSigned(Bureaucrat const &bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;

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
		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
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

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif