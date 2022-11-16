/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:21:27 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:21:27 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

// Colors
# define GREEN	"\033[0;32m"
# define RED 	"\033[0;31m"
# define ORANGE	"\033[0;33m"
# define CYAN	"\033[0;36m"
# define NC     "\033[0m"

// Libs
# include <iostream>
# include <string>
# include <unistd.h>

class ClapTrap
{
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const &instance );
		~ClapTrap( void );

		ClapTrap &operator=( ClapTrap const &rhs );

		void	    attack( std::string const &target );
		void	    takeDamage( unsigned int amount );
		void	    beRepaired( unsigned int amount );

		void	    setName( std::string name );
		void	    setEnergyPoints( unsigned int energyPoints );
		void	    setAttackDamage( unsigned int attackDamage );
		void	    setHitPoints( unsigned int hitPoints );

		std::string	getName( void ) const;
		int		    getHitPoints( void ) const;
		int		    getEnergyPoints( void ) const;
		int		    getAttackDamage( void ) const;

		int         energyCost( void );

	protected:
		std::string	_name; // Name of the ClapTrap instance
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	private:
};

#endif