/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:20:27 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:16:52 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie* newZombie( std::string name ) {
	return (new Zombie(name));
};
