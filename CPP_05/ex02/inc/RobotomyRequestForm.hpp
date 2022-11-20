/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:23:11 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:23:12 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <stdlib.h>
# include <time.h>

# include <exception>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &instance);
		~RobotomyRequestForm(void);

		RobotomyRequestForm		&operator=(RobotomyRequestForm const &rhs);

		virtual void			execute(Bureaucrat const &executor) const; // override
		std::string const		&getTarget(void) const;

		// Exceptions

	private:
		std::string				        _target;
};

#endif