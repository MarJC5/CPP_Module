/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:23:00 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:23:00 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &instance) : AForm(instance), _target(instance._target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

/******************************************************************************
 * OPERATORS
 */

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs); // Copying AForm attributes
	}
	return (*this);
}

/******************************************************************************
 * GETTERS / SETTERS
 */

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	/* Check if the form is signed and if the executor has the right grade */
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else {
		/* Execute the form */
		std::cout << GREY
					<< this->_target
					<< NC
					<< " has been pardoned by Zafod Beeblebrox."
					<< std::endl;
	}
}