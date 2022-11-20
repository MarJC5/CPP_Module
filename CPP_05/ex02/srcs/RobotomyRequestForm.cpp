/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:23:07 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:23:07 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &instance) : AForm(instance), _target(instance.getTarget())
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

/******************************************************************************
 * OPERATORS
 */

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
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

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	/* Check if the form is signed and if the executor has the right grade */
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else {
		/* Execute the form with 50% chance */
		std::cout << "* Makes some drilling noise *" << std::endl;
		srand(time(NULL));
		int random = rand() % 2;
		std::cout << this->_target
		          << " robotomy ";
		if (random == 0)
			std::cout << GREY
						<< "successfull"
						<< NC
						<< std::endl;
		else
			std::cout << GREY
						<< "failed"
						<< NC
						<< std::endl;
	}
}

/******************************************************************************
 * GETTERS / SETTERS
 */

std::string const		&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}
