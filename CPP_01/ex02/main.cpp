/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:32:07 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:13 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string  str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The address of the str in memory: " << &str << std::endl;
	std::cout << "The address saved in stringPTR: " << stringPTR << std::endl;
	std::cout << "The address saved in stringREF: " << &stringREF << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "The value of str: " << str << std::endl;
	std::cout << "The value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed by stringREF: " << stringREF << std::endl;

	return (0);
}