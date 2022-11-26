/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/26 15:33:16 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPES_HPP
#define SCALARTYPES_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <limits>
#include <string>
#include <cctype>

class ScalarTypes
{
	public:
		ScalarTypes(void);
		ScalarTypes(std::string str);
		ScalarTypes(ScalarTypes const &instance);
		~ScalarTypes(void);
		
		ScalarTypes	&operator=(ScalarTypes const &rhs);

		void	convert(void);

	private:
		std::string	_str;
		float		_float;
		double		_double;

		void		_convChar(void);
		void		_convInt(void);
		void		_convFloat(void);
		void		_convDouble(void);
};

#endif