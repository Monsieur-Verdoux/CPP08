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
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator; // typedef for the reverse iterator type of the container
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator; // typedef for the const reverse iterator type of the container

		iterator begin(); // begin() function to return the beginning of the stack
		iterator end(); // end() function to return the end of the stack
		const_iterator begin() const; // const begin() function to return the beginning of the stack
		const_iterator end() const; // const end() function to return the end of the stack

		reverse_iterator rbegin(); // reverse begin() function to return the reverse beginning of the stack
		reverse_iterator rend(); // reverse end() function to return the reverse end of the stack
		const_reverse_iterator rbegin() const; // const reverse begin() function to return the reverse beginning of the stack
		const_reverse_iterator rend() const; // const reverse end() function to return the reverse end of the stack
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin(); // return the beginning of the container (bottom), c is the underlying container of the stack, which is a deque by default
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() //
{
	return this->c.end(); // return the end of the container, which is the top of the stack
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin(); // return the beginning of the container
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const 
{
	return this->c.end(); // return the end of the container
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() 
{
	return this->c.rbegin(); // return the reverse beginning of the container
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() 
{
	return this->c.rend(); // return the reverse end of the container
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const 
{
	return this->c.rbegin(); // return the reverse beginning of the container
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const 
{
	return this->c.rend(); // return the reverse end of the container
}


