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
#include <random>

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
		std::cout << sp << std::endl;
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
		
		std::random_device rd; // Random device to seed the random number generator, hardware entropy source
		std::mt19937 gen(rd()); // Mersenne Twister random number generator seeded with the random device
		std::uniform_int_distribution<> dist(0, 99999); // Uniform distribution between 0 and 99999

		std::vector<int> randomNumbers;
		randomNumbers.reserve(10000); // Reserve space for 10000 elements
		for (int i = 0; i < 10000; ++i)
		{
			randomNumbers.push_back(dist(gen)); // Generate random numbers and add them to the vector
		}
		sp.addNumbers(randomNumbers.begin(), randomNumbers.end()); // Add the random numbers to the span
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	return 0;
}