/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:55:24 by magonzal          #+#    #+#             */
/*   Updated: 2023/12/21 21:52:52 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <vector>
#include <list>
#include <iostream>
#include <stack>

# define RESET				"\x1b[0m"
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE 				"\x1b[34m"


template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		~MutantStack(void) {}

		MutantStack &operator=(const MutantStack &other)
		{
			if(this != &other)
				*this = other;
			return *this;
		}
		typedef typename std::stack<T>::container_type::iterator 				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator begin(void)
		{
			return this->c.begin();
		};
		const_iterator cbegin(void) const
		{
			return this->c.cbegin();
		};
		
		iterator end(void)
		{
			return this->c.end();
		};
		const_iterator cend(void) const
		{
			return this->c.cend();
		};

		reverse_iterator rbegin(void)
		{
			return this->c.rbegin();
		};
		const_reverse_iterator crbegin(void) const
		{
			return this->c.crbegin();
		};
		reverse_iterator rend(void)
		{
			return this->c.rend();
		};
		const_reverse_iterator crend(void) const
		{
			return this->c.crend();
		};
};

#endif
