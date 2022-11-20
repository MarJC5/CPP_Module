/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:23:14 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:23:14 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

/******************************************************************************
 * ASCII ART
 */

std::string const	ShrubberyCreationForm::_tree =
	"    ccee88oo\n"
	"  C8O8O8Q8PoOb o8oo\n"
	" dOB69QO8PdUOpugoO9bD\n"
	"CgggbU8OU qOp qOdoUOdcb\n"
	"    6OuU  /p u gcoUodpP\n"
	"      \\\\\\//  /douUP\n"
	"        \\\\\\////\n"
	"         |||/\\\n"
	"         |||\\/\n"
	"         |||||\n"
	"   .....//||||\\....";

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &instance) : AForm(instance.getName(), instance.getGradeToSign(), instance.getGradeToExecute()), _target(instance.getTarget())
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

/******************************************************************************
 * OPERATORS
 */

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs); // Copying AForm attributes
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	/* Check if the form is signed and if the executor has the right grade */
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else {
		/* Create the file */
		std::string         filename = this->getTarget() + "_shrubbery";
		std::ofstream       file(filename);

		if (!file.is_open())
			throw ShrubberyCreationForm::FormFileNotOpenException();
		file << ShrubberyCreationForm::_tree;
		if (!file.good())
			throw ShrubberyCreationForm::FormFileWriteException();

		file.close();
		std::cout << "Shrubbery created in file " << filename << std::endl;
	}
}

/******************************************************************************
 * GETTERS / SETTERS
 */

std::string const	&ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

/******************************************************************************
 * EXCEPTIONS
 */

const char* ShrubberyCreationForm::FormFileNotOpenException::what() const throw() {
	return ("Shrubbery Creation Form: File not open");
}

const char* ShrubberyCreationForm::FormFileWriteException::what() const throw() {
	return ("Shrubbery Creation Form: Cannot write to file");
}