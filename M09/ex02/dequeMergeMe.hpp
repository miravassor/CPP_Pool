/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeMergeMe.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:59:53 by avassor           #+#    #+#             */
/*   Updated: 2023/12/12 14:31:19 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PmergeMe.hpp"


template <typename Container>
class dequeMergeMe : public PmergeMe<std::deque<int> > {
	protected:
		typedef std::deque<int>::iterator iter;
		typedef std::deque<std::pair<int, int> >::iterator pairIt;

		std::deque<std::pair<int, int> >	_pairContainer;

		bool	findDuplicate(int input);
		void	printInit();
		void	makePair();
		void	verifySort();
		void	printResult();
		void	insert(int index);
		void	pushSorted();
		void	insertPend();
		void	binarySearch(iter key, iter start, iter end, int index);
	public:
		dequeMergeMe() {};
		~dequeMergeMe() {};
		dequeMergeMe(dequeMergeMe& tocopy);
		dequeMergeMe& operator=(const dequeMergeMe &rhs);
		void	run(int argc, char **argv);
};

