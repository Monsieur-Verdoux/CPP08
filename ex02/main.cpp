/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 01:38:26 by akovalev          #+#    #+#             */
/*   Updated: 2025/04/24 01:38:26 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

// int main()
// {
// 	MutantStack<int> mutant;
// 	mutant.push(343);
// 	mutant.push(123);
// 	mutant.push(456);

// 	std::cout << "MutantStack elements: ";
// 	for (MutantStack<int>::iterator it = mutant.begin(); it != mutant.end(); ++it)
// 		std::cout << *it << " ";

// 	std::cout << std::endl;

// 	std::cout << "Top element: " <<  mutant.top(); // access the top element
// 	mutant.pop(); // pop the last element
// 	std::cout << std::endl;
// 	std::cout << "After pop: ";

// 	for (MutantStack<int>::iterator it = mutant.begin(); it != mutant.end(); ++it)
// 		std::cout << *it << " ";
	
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	std::cout << "-------------------------" << std::endl;
	std::cout << "Now with list" << std::endl;
	
	std::list <int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	return 0;

}