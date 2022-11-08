/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:18:16 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:18:17 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include "Replace.h"

class Replace {

	public:
		Replace( std::string filename );
		~Replace( void );

		void		setFilename( std::string filename );
		void        replace( std::string s1, std::string s2 ); // replace s1 by s2

	private:
		std::string _filename;

		void	    _read( std::string s1, std::string s2 ) const; // read the file
		void	    _write( std::string s1, std::string s2, std::ifstream *fd ) const; // write the file
};

#endif
