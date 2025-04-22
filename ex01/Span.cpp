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

Span::Span(unsigned int N) : _size(N), _max(0), _min(0)
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &original) : _set(original._set), _size(original._size), _max(original._max), _min(original._min)
{
	std::cout << "Span copy constructor called" << std::endl;
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
	if (_set.size() == 1)
	{
		_max = num;
		_min = num;
	}
	else
	{
		if (num > _max)
			_max = num;
		if (num < _min)
			_min = num;
	}
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
	for (auto it = _set.begin(); it != --_set.end(); ++it) // --_set.end() is used to get the last element of the set
	{
		int span = *(std::next(it)) - *it;
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::getSize() const
{
	return _size;
}

int Span::findByIndex(unsigned int index) const
{
	if (index >= this->getSize())
		throw std::out_of_range("Index out of range");
	auto it = _set.begin();
	std::advance(it, index); // advance the iterator to the index position
	return *it;
}

std::ostream& operator<<(std::ostream &out, const Span &span)
{
	out << "Span: ";
	for (size_t i = 0; i < span.getSize(); i++)
	{
		if (i != 0)
			out << ", ";
		out << span.findByIndex(i);
	}
	return out;
}

