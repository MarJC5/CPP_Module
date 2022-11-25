/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/25 10:20:09 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <unistd.h>

static void	tic_tac(int usleep_time, int duration, std::string color)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << color << "↓" << NC << std::endl;
		usleep(usleep_time);
	}
}

int main(void)
{
	{
		std::cout << GREEN << "Should work" << NC << std::endl;
		Bureaucrat Bureaucrat1("Jonathan", 1);
		std::cout << Bureaucrat1 << std::endl;
		tic_tac(500000, 2, GREEN);
		
		try // Try to create the form
		{
			Form Form4("Battle Tendency", 1, 1);
			std::cout << Form4 << std::endl;

			try // Try to signe the form
			{
				Bureaucrat1.signForm(Form4); // Should work
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl; // Error if form cannot be signed
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl; // Error if form cannot be created du to wrong grade
		}
	}
	
	tic_tac(500000, 2, NC);

	{
		std::cout << RED << "Should throw exception" << NC << std::endl;
		Bureaucrat Bureaucrat1("Josuke", 150);
		std::cout << Bureaucrat1 << std::endl;
		tic_tac(500000, 2, RED);
		
		try // Try to create the form
		{
			Form Form4("Diamond is Unbreakable", 1, 1);
			std::cout << Form4 << std::endl;

			try // Try to signe the form
			{
				Bureaucrat1.signForm(Form4); // Should throw an exception as it is out of range
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl; // Error if form cannot be signed
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl; // Error if form cannot be created du to wrong grade
		}
	}

	return (0);
}