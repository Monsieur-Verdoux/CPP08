/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:42:59 by akovalev          #+#    #+#             */
/*   Updated: 2025/04/18 14:42:59 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <array>

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::list<int> lst = {1, 2, 3, 4, 5};
	std::array<int, 5> arr = {1, 2, 3, 4, 5};

	try
	{
		auto it = easyfind(vec, 3);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Vector test: " << e.what() << std::endl;
	}

	try
	{
		auto it = easyfind(lst, 6);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "List test: " << e.what() << std::endl;
	}

	try
	{
		auto it = easyfind(arr, 5);
		std::cout << "Found in array: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Array test: " << e.what() << std::endl;
	}

	return 0;
}