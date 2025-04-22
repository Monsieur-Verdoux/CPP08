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

class Span
{
	private:
		std::multiset<int> _set; // multiset is a container that stores elements in a specific order and allows duplicate elements
		unsigned int _size;
		int _max;
		int _min;
	public:
		Span() = delete;
		Span& operator=(const Span &original) = delete;
		Span(unsigned int N);
		Span(const Span &original);

		~Span();
		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;
		unsigned int getSize() const;
		int findByIndex(unsigned int index) const;
};

std::ostream& operator<<(std::ostream &out, const Span &span);