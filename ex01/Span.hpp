/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:26:11 by akovalev          #+#    #+#             */
/*   Updated: 2025/04/23 01:26:11 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <set>
#include <stdexcept>
#include <iterator>

class Span
{
	private:
		std::multiset<int> _set; // multiset is a container that stores elements in a specific order and allows duplicate elements
		unsigned int _size;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &original);
		Span& operator=(const Span &original);
		~Span();

		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;
		unsigned int getSize() const;
		const std::multiset<int>& getSet() const;
		template <typename iteratorType>
		void addNumbers(iteratorType begin, iteratorType end);
};

std::ostream& operator<<(std::ostream &out, const Span &span);

template <typename iteratorType>
void Span::addNumbers(iteratorType begin, iteratorType end)
{
	if (std::distance(begin, end) + _set.size() > _size)
		throw std::runtime_error("Not enough space in span to add numbers");
	_set.insert(begin, end); // insert the range of numbers into the multiset
}