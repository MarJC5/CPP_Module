/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:20:37 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:16:57 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

// Colors
# define GREEN	"\033[0;32m"
# define RED 	"\033[0;31m"
# define ORANGE	"\033[0;33m"
# define CYAN	"\033[0;36m"
# define NC     "\033[0m"

void randomChump( std::string name );

#endif