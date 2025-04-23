/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:26:04 by akovalev          #+#    #+#             */
/*   Updated: 2025/04/23 01:26:04 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _size(N)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &original) : _set(original._set), _size(original._size)
{
	std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span &original)
{
	if (this != &original) {
		_set = original._set;
		_size = original._size;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int num)
{
	if (_set.size() >= _size)
		throw std::runtime_error("Span is full");
	_set.insert(num);
}


int Span::longestSpan() const
{
	if (_set.size() < 2)
		throw std::runtime_error("Not enough elements to find longest span");
	return (*_set.rbegin() - *_set.begin());
}

int Span::shortestSpan() const
{
	if (_set.size() < 2)
		throw std::runtime_error("Not enough elements to find shortest span");
	int minSpan = *_set.rbegin() - *_set.begin();
	auto prevIt = _set.begin();
	for (auto it = std::next(_set.begin()); it != _set.end(); ++it, ++prevIt)
	{
		int span = *it - *prevIt;
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::getSize() const
{
	return _size;
}

const std::multiset<int>& Span::getSet() const 
{
	return _set;
}

std::ostream& operator<<(std::ostream &out, const Span &span)
{
	out << "Span: ";
	size_t i = 0;
	for (const auto& val : span.getSet())
	{
		if (i++ > 0)
			out << ", ";
		out << val;
	}
	return out;
}

