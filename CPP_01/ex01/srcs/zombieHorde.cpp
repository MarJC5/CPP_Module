/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:21:13 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name ) {
	if (N <= 0)
		return (NULL);
	Zombie *Horde = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		Horde[i].setName(std::string(name + "_" + std::to_string(i + 1)));
	}
	return (Horde);
};