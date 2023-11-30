/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:54:43 by magonzal          #+#    #+#             */
/*   Updated: 2023/11/30 17:54:45 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	public:

		Span(const unsigned int N);
		Span(const Span &other);
		~Span(void);

		Span	&operator=(const Span &other);

		void	addNumber(const int newnb);
		void	addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);

		long int	shortestSpan(void);
		long int	longestSpan(void);

	private:

		Span(void);

		unsigned int		_size;
		std::vector<int>	_nbs;

		class NumberFullException: public std::exception
		{
			public:

				const char*	what(void) const throw();
		};

		class EmptySpanException: public std::exception
		{
			public:

				const char*	what(void) const throw();
		};

};

#endif
