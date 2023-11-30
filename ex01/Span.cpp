/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:54:48 by magonzal          #+#    #+#             */
/*   Updated: 2023/11/30 17:55:04 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _size(0), _nbs() {}

Span::Span(const unsigned int N) : _size(N), _nbs() {}

Span::Span(const Span &other) : _nbs()
{
	*this = other;
}

Span::~Span(void) {}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_nbs = other._nbs;
	}
	return (*this);
}

void	Span::addNumber(const int newnb)
{
	if (_nbs.size() < _size)
		_nbs.push_back(newnb);
	else
		throw (NumberFullException());
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (_size >= (_nbs.size() + std::distance(start, end)))
		_nbs.insert(_nbs.end(), start, end);
	else
		throw (NumberFullException());
}

long int Span::shortestSpan(void)
{
	if (_nbs.size() > 1)
	{
		long int	span;
		long int	temp;
		std::vector<int>::iterator it;
		std::vector<int>::iterator it2;

		span = longestSpan();
		temp = 0;
		for (it = _nbs.begin(); it != _nbs.end(); it++)
		{
			for (it2 = it; it2 != _nbs.end(); it2++)
			{
				if (it != it2)
				{
					temp = std::abs(static_cast<long int>(*it) - static_cast<long int>(*it2));
					if (temp < span)
						span = temp;
				}
			}
		}
		return (span);
	}
	else
		throw (EmptySpanException());
}

long int Span::longestSpan(void)
{
	if (_nbs.size() > 1)
	{
		std::vector<int>::iterator itmax;
		std::vector<int>::iterator itmin;

		itmax = std::max_element(_nbs.begin(), _nbs.end());
		itmin = std::min_element(_nbs.begin(), _nbs.end());
		return (static_cast<long int>(*itmax) - static_cast<long int>(*itmin));
	}
	else
		throw (EmptySpanException());
}

const char *	Span::NumberFullException::what(void) const throw()
{
	return ("vector is full");
}

const char *	Span::EmptySpanException::what(void) const throw()
{
	return ("empty span");
}
