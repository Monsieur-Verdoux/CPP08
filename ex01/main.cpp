/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:26:22 by akovalev          #+#    #+#             */
/*   Updated: 2025/04/23 01:26:22 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(100);
		sp.addNumber(13);
		sp.addNumber(-7);
		sp.addNumber(86);
		sp.addNumber(22);

		std::cout << "Elements in span: ";
		std::cout << sp << std::endl; // This will call the overloaded operator<<

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		try
		{
			sp.addNumber(6); // This will throw an exception because the span is full
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		Span sp = Span(10000);
		srand(time(0)); // Seed for random number generation
		for (int i = 0; i < 10000; ++i)
		{
			sp.addNumber(rand() % 100000); // Add random numbers to the span
		}
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "Elements in span: ";
	}

	return 0;
}