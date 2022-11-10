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

Replace::Replace( std::string filename ): _filename(filename) {
	this->_s1 = "";
	this->_s2 = "";
};

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
	if (this->_filename.empty()) {
		std::cout << "No filename given." << std::endl;
		return ;
	}
	this->_read(s1, s2);
}

void    Replace::showDiff( void ) const {
	std::ifstream ifs(this->_filename);
	std::ifstream ifsReplace(this->_filename + ".replace");
	if (ifsReplace.is_open()) {
		// Initial file
		if (ifs.is_open()) {
			std::cout << ifs.rdbuf() << std::endl;
			ifs.close();
			std::cout << std::endl;
		} else {
			std::cout << "Unable to open [original file]" << std::endl;
		}
		// Replace file
		std::cout << CYAN << std::endl;
		std::cout << ifsReplace.rdbuf() << NC << std::endl;
		ifsReplace.close();
	} else {
		std::cout << "Unable to open [file].replace or [file].replace doesn't exist." << std::endl;
	}
}