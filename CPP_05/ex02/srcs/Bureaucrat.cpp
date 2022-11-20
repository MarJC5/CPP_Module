/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:35 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:36 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	/* Check if grade is valid */
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &instance) : _name(instance.getName()), _grade(instance._grade)
{
	/* Check if grade is valid */
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

/******************************************************************************
 * OPERATORS
 */

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	return ;
}

void    Bureaucrat::executeForm(AForm const &form)
{
	try {
		form.execute(*this);
		std::cout << GREY
					<< this->_name
					<< NC
					<< " executes "
					<< form.getName()
					<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << GREY
		          << this->_name
		          << NC
				  << " could not execute the form "
				  << form.getName()
				  << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

/******************************************************************************
 * GETTERS
 */

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/******************************************************************************
 * EXCEPTIONS
 */

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat Error: Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Error: Grade too low");
}

/******************************************************************************
 * NON MEMBER FUNCTIONS
 */

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << GREY
		<< rhs.getName()
		<< NC
		<< ", bureaucrat grade "
		<< GREY
		<< rhs.getGrade()
		<< NC;
	return (o);
}
