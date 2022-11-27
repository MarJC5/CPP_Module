/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:25:05 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:25:05 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>
# include <cstdlib>

class Span
{
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);

		Span &operator=(Span const &rhs);

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end); // add a range of numbers
		int		shortestSpan(void);
		int		longestSpan(void);

		unsigned int	    getN(void) const;
		std::vector<int>	getV(void) const;

		class	FullException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("Span is full");
				};
		};

		class	NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("Span is empty");
				};
		};

		class	NoRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("Span has only one number");
				};
		};

	private:
		unsigned int		_n;
		std::vector<int>	_v;
};

std::ostream &operator<<(std::ostream &o, Span const &i);

#endif