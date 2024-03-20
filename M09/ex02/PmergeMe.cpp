/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:00:03 by avassor           #+#    #+#             */
/*   Updated: 2023/12/12 15:26:27 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Build

template <typename Container>
PmergeMe<Container>::PmergeMe(PmergeMe<Container>& tocopy) {
	*this = tocopy;
}

template <typename Container>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe<Container> &rhs) {
	if (this != &rhs) {
		_container = rhs._container;
		_sContainer = rhs._sContainer;
		_pendContainer = rhs._pendContainer;
		_jacobContainer = rhs._jacobContainer;
		_timeStart = rhs._timeStart;
		_timeEnd = rhs._timeEnd;
	}
	return (*this);
}

// Utils

template <typename Container>
bool	PmergeMe<Container>::isWholeNumber(double input) {
	return (std::fmod(input, 1.0) == 0.0);
}

// Time

template <typename Container>
double PmergeMe<Container>::microTime() {
	struct timeval current;
	gettimeofday(&current, NULL);
	return current.tv_sec + current.tv_usec / 1e6;
}

// Jacobsthal

template <typename Container>
int	PmergeMe<Container>::genJacob(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (genJacob(n - 1) + 2 * genJacob(n - 2));
}

template <typename Container>
void	PmergeMe<Container>::jacobsthal() {
	int	iJ = 3;
	for (long unsigned int i = 0; i <= _pendContainer.size(); ++i) {
		if (!_jacobContainer.empty() && static_cast<long unsigned int>(*(_jacobContainer.end() - 1)) > _container.size())
			return ;
		_jacobContainer.push_back(genJacob(iJ));
		++iJ;
	}
}
