/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:18:45 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:18:46 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./ex05 [debug|info|warning|error]" << std::endl;
		return (1);
	}
	Harl harl;
	harl.complain( std::string(argv[1]) );
	return (0);
}