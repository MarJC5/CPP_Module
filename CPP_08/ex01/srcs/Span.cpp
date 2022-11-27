/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:25:00 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:25:00 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

/* **************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Span::Span(void): _n(0) {}

Span::Span(unsigned int n) : _n(n)
{
	return ;
}

Span::Span(Span const &src)
{
	*this = src;
	return ;
}

Span::~Span(void)
{
	return ;
}

/* **************************************************************************
 * OPERATORS
 */

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_n = rhs.getN();
		this->_v = rhs.getV();
	}
	return (*this);
}

/* **************************************************************************
 * GETTERS / SETTERS
 */

unsigned int	Span::getN(void) const {
	return (this->_n);
}

std::vector<int>	Span::getV(void) const {
	return (this->_v);
}

/* **************************************************************************
 * MEMBER FUNCTIONS
 */

void	Span::addNumber(int n)
{
	if (this->_n == 0)
		throw Span::NoSpanException();
	else if (this->_v.size() == this->_n)
		throw Span::FullException();
	this->_v.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_n == 0)
		throw Span::NoSpanException();
	else if (this->_v.size() + (end - begin) > this->_n)
		throw Span::FullException();
	try
	{
		while (begin != end)
		{
			// is span full ?
			if (this->_v.size() == this->_n)
				throw Span::FullException();
			this->addNumber(*begin);
			begin++;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int		Span::shortestSpan(void)
{
	if ( this->_n == 0)
		throw Span::NoSpanException();
	else if (this->_v.size() < 2)
		throw Span::NoRangeException();

	std::vector<int>	v = this->_v;
	std::sort(v.begin(), v.end());

	int	span = v[1] - v[0];

	// compare all the values of the vector and keep the smallest
	for (unsigned int i = 1; i < v.size() - 1; i++)
	{
		if (v[i + 1] - v[i] < span)
			span = v[i + 1] - v[i];
	}
	return (span);
}

int		Span::longestSpan(void)
{
	if ( this->_n == 0)
		throw Span::NoSpanException();
	else if (this->_v.size() < 2)
		throw Span::NoRangeException();

	std::vector<int>	v = this->_v;

	std::sort(v.begin(), v.end()); // sort the vector
	return (v[v.size() - 1] - v[0]); // last - first
}

/* **************************************************************************
 * OVERLOADS << >>
 */

std::ostream	&operator<<(std::ostream &o, Span const &i)
{
	for (unsigned int j = 0; j < i.getV().size(); j++) {
		o << i.getV()[j];
		if (j != i.getV().size() - 1)
			o << ", ";
	}
	return (o);
}