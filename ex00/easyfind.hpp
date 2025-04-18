/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:42:54 by akovalev          #+#    #+#             */
/*   Updated: 2025/04/18 14:42:54 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <exception>

// The function uses the std::find algorithm to search for the value in the container.
//iterator is a type that points to an element in the container
//The iterator is used to traverse the container and find the value.

template <typename T>
typename T::iterator easyfind(T &cont, int val) // typename T::iterator means that it is a type and not a static member of the class
{
	auto it = std::find(cont.begin(), cont.end(), val); //auto is a type that is automatically deduced from the expression
	if (it == cont.end())
		throw std::runtime_error("Value not found in the container");
	return it;
}
