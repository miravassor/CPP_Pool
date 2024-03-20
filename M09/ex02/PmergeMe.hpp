/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:59:53 by avassor           #+#    #+#             */
/*   Updated: 2023/12/12 14:31:06 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <utility>
#include <fstream>

template <typename Container>
class PmergeMe {
	protected:
		typedef std::deque<int>::iterator iter;

		Container	_container;
		Container	_sContainer;
		Container	_pendContainer;
		Container	_jacobContainer;
		//time variables
		double	_timeStart;
		double	_timeEnd;
		// methods
		bool			isWholeNumber(double input);
		double			microTime();
		void			jacobsthal();
		int				genJacob(int n);
		bool			findDuplicate(int input);
		// virtual methods
		virtual void	makePair() = 0;
		virtual void	printResult() = 0;
		virtual void	insert(int index) = 0;
		virtual void	pushSorted() = 0;
		virtual void	insertPend() = 0;
	public:
		PmergeMe() {};
		virtual ~PmergeMe() {};
		PmergeMe(PmergeMe& tocopy);
		PmergeMe& operator=(const PmergeMe &rhs);
		virtual void	run(int argc, char **argv) = 0;
};
