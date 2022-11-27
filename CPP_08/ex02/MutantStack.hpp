/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:25:15 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:25:16 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

/*
 * Stack is a container adapter that gives the programmer the functionality of a stack - specifically, a LIFO (last-in first-out) data structure.
 *
 * Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.
 * The functions push and pop are used to add and remove elements from the stack container, respectively.
 * The function top returns a reference to the top element in the stack.
 * The underlying container may be any of the standard container class templates or some other specifically designed container class.
 * The container shall support the following operations:
 * empty, size, back, push_back, pop_back.
 * The standard container classes vector, deque and list fulfill these requirements.
 * By default, if no container class is specified for a particular stack class instantiation, the standard container deque is used.
 *
 */

template <typename T>
class MutantStack : public std::stack<T> // inherit from std::stack
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const & src) : std::stack<T>(src) {}
		virtual ~MutantStack() {}

		MutantStack &operator=(MutantStack const &rhs)
		{
			if (this != &rhs)
				std::stack<T>::operator=(rhs); // or this->c = rhs.c;
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin(void)
		{
			return (std::stack<T>::c.begin()); // or this->c.begin();
		}

		iterator	end(void)
		{
			return (std::stack<T>::c.end()); // or this->c.end();
		}
};

#endif