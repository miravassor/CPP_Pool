/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:08:27 by avassor           #+#    #+#             */
/*   Updated: 2023/11/27 14:31:57 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.cpp"
#include <list>

int main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "print 1st element:" << std::endl;
	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "print stack size:" << std::endl;
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "print stack elements using added iterators:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "copy constructor:" << std::endl;
	MutantStack<int> stack_copy(mstack);
	MutantStack<int>::iterator it2 = stack_copy.begin();
	MutantStack<int>::iterator ite2 = stack_copy.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	return 0;
}

// int main()
// {
// 	std::list<int>	list;

// 	list.push_back(5);
// 	list.push_back(17);
// 	std::cout << "print 1st element:" << std::endl;
// 	std::cout << list.back() << std::endl;

// 	list.pop_back();
// 	std::cout << "print list size:" << std::endl;
// 	std::cout << list.size() << std::endl;

// 	list.push_back(3);
// 	list.push_back(5);
// 	list.push_back(737);
// 	list.push_back(0);

// 	std::cout << "print list elements using iterators:" << std::endl;
// 	std::list<int>::iterator it = list.begin();
// 	std::list<int>::iterator ite = list.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}

// 	std::cout << "copy constructor:" << std::endl;
// 	std::list<int> list_copy(list);
// 	std::list<int>::iterator it2 = list_copy.begin();
// 	std::list<int>::iterator ite2 = list_copy.end();
// 	++it2;
// 	--it2;
// 	while (it2 != ite2)
// 	{
// 		std::cout << *it2 << std::endl;
// 		++it2;
// 	}
// 	return 0;
// }
