/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 01:38:57 by akovalev          #+#    #+#             */
/*   Updated: 2025/04/24 01:38:57 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <iterator>

//Mutant stack will inherit from the stack class and will be a template class
//to enable iteration over a container the container class must have a begin() and end() method
//The container class must also have a typedef for the iterator type and const iterator type
//std::stack uses a deque as the default container, so we can use the iterator of the deque class

template <typename T>
class MutantStack : public std::stack<T> // MutantStack inherits from std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator; //meaning: "Inside my MutantStack class, create a shorthand called iterator for the type std::deque<T>::iterator, which is the iterator type of the container that std::stack<T> uses."
		typedef typename std::stack<T>::container_type::const_iterator const_iterator; // typedef for the const iterator type of the container

		iterator begin(); // begin() function to return the beginning of the stack
		iterator end(); // end() function to return the end of the stack
		const_iterator begin() const; // const begin() function to return the beginning of the stack
		const_iterator end() const; // const end() function to return the end of the stack
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() // begin() function
{
	return this->c.begin(); // return the beginning of the container (bottom), c is the underlying container of the stack, which is a deque by default
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() // end() function
{
	return this->c.end(); // return the end of the container, which is the top of the stack
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const // const begin() function
{
	return this->c.begin(); // return the beginning of the container
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const // const end() function
{
	return this->c.end(); // return the end of the container
}

