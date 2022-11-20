/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:48 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:49 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
	return ;
}

Form::Form(Form const &instance): _name(instance.getName()), _gradeToSign(instance.getGradeToSign()), _gradeToExecute(instance.getGradeToExecute())
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
	return ;
}

Form::~Form(void)
{
	return ;
}

/******************************************************************************
 * OPERATORS
 */

Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
	return ;
}

/******************************************************************************
 * GETTERS
 */

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}

/******************************************************************************
 * EXCEPTIONS
 */

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade too low");
}

/******************************************************************************
 * NON MEMBER FUNCTIONS
 */

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form " << GREY << rhs.getName() << NC << " is " << GREY;
	if (!rhs.getSigned())
		o << "not ";
	o << "signed "
		<< NC
		<< "and requires a grade of "
		<< GREY
		<< rhs.getGradeToSign()
		<< NC
		<< " to sign and a grade of "
		<< GREY
		<< rhs.getGradeToExecute()
		<< NC
		<< " to execute.";
	return (o);
}
