/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:42 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPES_HPP
# define SCALARTYPES_HPP

# define NaN

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <exception>

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

		class ImpossibleException: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("impossible");
				}
		};

		class NonDisplayableException: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("Non displayable");
				}
		};

		class NanException: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("nan");
				};
		};

		class NanfException: public std::exception
	{
		public:
		virtual const char* what() const throw() {
			return ("nanf");
		};
	};

	private:
		std::string _str;
		int		    _int;
		char	    _char;
		float	    _float;
		double	    _double;
};

#endif