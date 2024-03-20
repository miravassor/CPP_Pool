/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorMergeMe.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:14:48 by avassor           #+#    #+#             */
/*   Updated: 2023/12/12 14:53:28 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PmergeMe.hpp"

template <typename Container>
class vectorMergeMe : public PmergeMe<std::vector<int> > {
	protected:
		typedef std::vector<int>::iterator iter;
		typedef std::vector<std::pair<int, int> >::iterator pairIt;

		std::vector<std::pair<int, int> >	_pairContainer;

		bool	findDuplicate(int input);
		void	makePair();
		void	verifySort();
		void	printResult();
		void	insert(int index);
		void	pushSorted();
		void	insertPend();
		void	binarySearch(iter key, iter start, iter end, int index);
	public:
		vectorMergeMe() {};
		~vectorMergeMe() {};
		vectorMergeMe(vectorMergeMe& tocopy);
		vectorMergeMe& operator=(const vectorMergeMe &rhs);
		void	run(int argc, char **argv);
};
