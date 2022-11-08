/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:20:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:01 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	int N = 5;

	Zombie  *newHorde = zombieHorde(N, std::string("Franky"));
	if (newHorde != NULL) {
		for (int i = 0; i < N; ++i) {
			newHorde[i].announce();
		}
	}
	delete[] newHorde;
	return (0);
}