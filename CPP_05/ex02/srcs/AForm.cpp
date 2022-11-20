/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:48 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:49 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(AForm const &instance): _name(instance.getName()), _gradeToSign(instance.getGradeToSign()), _gradeToExecute(instance.getGradeToExecute())
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

AForm::~AForm(void)
{
	return ;
}

/******************************************************************************
 * OPERATORS
 */

AForm	&AForm::operator=(AForm const &rhs)
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

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

/******************************************************************************
 * GETTERS
 */

std::string const	&AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

/******************************************************************************
 * EXCEPTIONS
 */

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form Error: Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form Error: Grade too low");
}

const char* AForm::FormAlreadySignedException::what() const throw() {
	return ("Form Error: Form already signed");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form Error: Form not signed");
}

/******************************************************************************
 * NON MEMBER FUNCTIONS
 */

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
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
