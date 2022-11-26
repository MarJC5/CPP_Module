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
#define SCALARTYPES_HPP

#include <iostream>
#include <exception>
#include <string>

#define INT				0
#define FLOAT			1
#define DOUBLE			2
#define CHAR			3
#define PSEUDO_LITERAL	4

class ScalarTypes
{
	private:
	char		*_str;
	int			_type;
	char		_char;
	int			_int;
	float		_float;
	double		_double;

	void		_detectType(void);

	static bool	_isDisplayableNANChar(char *str);
	static bool	_isInt(char *str);
	static bool	_isFloat(char *str);
	static bool	_isDouble(char *str);
	static bool	_isPseudoLiteral(char *str);
	static bool	_isFloatPseudoLiteral(std::string arg);
	static bool	_isDoublePseudoLiteral(std::string arg);

	void		_convertFromChar(void);
	void		_convertFromNums(void);
	void		_convertFromInt(void);
	void		_convertFromFloat(void);
	void		_convertFromDouble(void);

	static void	_defineFormatAndPrecision(void);
	void		_displayPseudoLiteral(void);
	static char	*_pseudoLiteralToDouble(char *str);
	void		_charDisplay(void);
	void		_numberDisplay(void);
	bool		_typeOverflow(double checkValue);
	bool		_intOverflow(double checkValue);
	bool		_floatOverflow(double checkValue);
	bool		_doubleOverflow(double checkValue);
	static void	_displayImpossible(void);
	void		_displayChar(double checkValue);
	static bool	_isDisplayableChar(char c);
	void		_displayInt(double checkValue);
	void		_displayFloat(double checkValue);
	void		_displayDouble(double checkValue);

	ScalarTypes(void);

	class TypeNotFound : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("\e[0;31mvalue is neither int, float, double or printable char\e[0m");
		}
	};

	public:
	ScalarTypes(char *str);
	ScalarTypes(ScalarTypes const &instance);
	~ScalarTypes(void);
	ScalarTypes	&operator=(ScalarTypes const &right_hand_side);

	void				display(void);
};

#endif