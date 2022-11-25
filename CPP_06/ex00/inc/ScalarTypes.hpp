/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/25 19:36:40 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPES_HPP
# define SCALARTYPES_HPP

# define IS_NAN 1
# define IS_INT 2
# define IS_CHAR 3
# define IS_FLOAT 4

# include <iostream>
# include <string>
# include <iomanip>

class ScalarTypes
{
	public:
		ScalarTypes(void);
		ScalarTypes(std::string value);
		ScalarTypes(ScalarTypes const &instance);
		virtual ~ScalarTypes(void);

		ScalarTypes &operator=(ScalarTypes const & rhs);

		void        display(void);
		void        checkType(void);

		void        fromChar(void);
		void        fromInt(void);
		void        fromFloat(void);
		void        fromDouble(void);

		void        setStr(std::string str);
		std::string	getStr(void) const;

		char		getChar(void) const;
		int			getInt(void) const;
		float		getFloat(void) const;
		double		getDouble(void) const;

	private:
		std::string _str;
		int			_type;

		int		    _int;
		char	    _char;
		float	    _float;
		double	    _double;

		bool		_isInt(void);
		bool		_isChar(void);
		bool		_isFloat(void);
		bool		_isDouble(void);
		bool		_isNanInf(void);
};

#endif