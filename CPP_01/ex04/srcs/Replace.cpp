/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:18:16 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:18:17 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Replace.hpp"

Replace::Replace( std::string filename ): _filename(filename) {};

Replace::~Replace( void ) {};

void    Replace::setFilename(std::string filename) {
	this->_filename = filename;
}

void    Replace::_write( std::string s1, std::string s2, std::ifstream *fd ) const {
	std::ofstream ofs;
	ofs.open(this->_filename + ".replace");
	if (ofs.is_open()) {
		std::string line;
		while (std::getline(*fd, line, '\0')) {
			size_t pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos) {
				line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
				pos += s2.length();
			}
			ofs << line << std::endl;
		}
		ofs.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
}

void    Replace::_read( std::string s1, std::string s2 ) const {
	std::ifstream ifs(this->_filename);
	if (ifs.is_open()) {
		this->_write(s1, s2, &ifs);
		ifs.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
}

void    Replace::replace( std::string s1, std::string s2 ) {
	this->_read(s1, s2);
}
