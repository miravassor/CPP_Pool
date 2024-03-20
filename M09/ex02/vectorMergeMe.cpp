/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorMergeMe.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:17:40 by avassor           #+#    #+#             */
/*   Updated: 2023/12/12 15:25:51 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorMergeMe.hpp"

// Build

template <typename Container>
vectorMergeMe<Container>::vectorMergeMe(vectorMergeMe<Container>& tocopy) {
	*this = tocopy;
}

template <typename Container>
vectorMergeMe<Container>&	vectorMergeMe<Container>::operator=(const vectorMergeMe<Container> &rhs) {
	if (this != &rhs) {
		_container = rhs._container;
		_pairContainer = rhs._pairContainer;
		_sContainer = rhs._sContainer;
		_pendContainer = rhs._pendContainer;
		_jacobContainer = rhs._jacobContainer;
		_timeStart = rhs._timeStart;
		_timeEnd = rhs._timeEnd;
	}
	return (*this);
}

// Methods

template <typename Container>
void	vectorMergeMe<Container>::run(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		std::string curr = argv[i];
		double	input = atof(curr.c_str());
		if (input < 0 || input > INT_MAX || !isWholeNumber(input)) {
			std::cout << "Error: overflow or negative value" << std::endl;
			std::cout << "Program needs positive integer values" << std::endl;
			return;
		}
		if (!findDuplicate(input))
			_container.push_back(input);
		else {
			std::cout << "Error: duplicate value found for: " << input << std::endl;
			return ;
		}
	}
	_timeStart = microTime();
	makePair();
	insert(_pairContainer.size() - 1);
	pushSorted();
	jacobsthal();
	insertPend();
	_timeEnd = microTime();
	// verifySort();
	printResult();
}

template <typename Container>
void	vectorMergeMe<Container>::makePair() {
	typename Container::iterator start = _container.begin();
	typename Container::iterator end = _container.end();
	for (; start != end; start += 2) {
		if (*start > *(start + 1))
			_pairContainer.push_back(std::pair<int , int>(*(start + 1) ,*start));
		else
			_pairContainer.push_back(std::pair<int , int>(*start, *(start + 1)));
		if (start + 2 == end || start + 2 + 1 == end)
			break;
	}
}

template <typename Container>
void	vectorMergeMe<Container>::insert(int index) {
	if (index > 0)
		insert (index - 1);

	std::pair<int, int>	tmp = _pairContainer[index];
	int prev = index - 1;

	while (prev >= 0 && _pairContainer[prev].second > tmp.second) {
		_pairContainer[prev + 1] = _pairContainer[prev];
		--prev;
	}
	if (prev + 1 != index)
		_pairContainer[prev + 1] = tmp;
}

template <typename Container>
void	vectorMergeMe<Container>::pushSorted() {
	for (long unsigned int i = 0; i != _pairContainer.size(); ++i) {
		_sContainer.push_back(_pairContainer[i].second);
		_pendContainer.push_back(_pairContainer[i].first);
	}
	_sContainer.insert(_sContainer.begin(), *_pendContainer.begin());
	_pendContainer.erase(_pendContainer.begin());
}

template <typename Container>
void	vectorMergeMe<Container>::insertPend() {
	while (!_pendContainer.empty()) {
		iter	start = _sContainer.begin();
		iter	end = _sContainer.end();

		if (_jacobContainer.empty() || static_cast<long unsigned int>(_jacobContainer.front()) > _sContainer.size()) {
			binarySearch(_pendContainer.begin(), start, end, 0);
			_pendContainer.erase(_pendContainer.begin());
		}
		else {
			int	index = *_jacobContainer.begin() - 1;
			binarySearch(_pendContainer.begin(), start, end, index);
			_pendContainer.erase(_pendContainer.begin());
			_jacobContainer.erase(_jacobContainer.begin());
		}
	}
	if (_container.size() % 2 != 0) {
		iter	start = _sContainer.begin();
		iter	end = _sContainer.end();
		binarySearch((_container.end() - 1), start, end, 0);
	}
}

template <typename Container>
void	vectorMergeMe<Container>::binarySearch(iter key, iter start, iter end, int index) {
	if (start >= end)
		return;
	if (*key < *_sContainer.begin()) {
		_sContainer.insert(_sContainer.begin(), *key);
		return;
	}
	if (*key > *(_sContainer.end() - 1)) {
		_sContainer.push_back(*key);
		return ;
	}
	iter	mid;
	if (!index)
		mid = start + (end - start) / 2;
	else
		mid = _sContainer.begin() + index;
	if (*key < *mid && *key > *(mid - 1))
		_sContainer.insert(mid, *key);
	else if (*key > *mid)
		binarySearch(key, mid + 1, end, 0);
	else
		binarySearch(key, start, mid, 0);
}

// Util

template <typename Container>
bool	vectorMergeMe<Container>::findDuplicate(int input) {
	for (iter it = _container.begin(); it != _container.end(); ++it) {
		if (*it == input)
			return 1;
	}
	return 0;
}

// Print

template <typename Container>
void	vectorMergeMe<Container>::printResult() {
	std::cout << "Time to process a range of " << _container.size();
	std::cout << " elements with std::vector: ";
	std::cout << std::fixed << std::setprecision(6) << _timeEnd - _timeStart;
	std::cout << " seconds" << std::endl;
}

template <typename Container>
void vectorMergeMe<Container>::verifySort() {
	if (_sContainer.empty()) return;
	// VERIFY SORTING IS OK
	iter prevIt = _sContainer.begin();
	for (iter currIt = prevIt + 1; currIt != _sContainer.end(); ++currIt) {
		if (*prevIt > *currIt) {
			std::cout << "\033[1;31mERROR: SORTING\033[0m" << std::endl;
			return;
		}
		prevIt = currIt;
	}
	// VERIFY SIZE OF ENTRY VS RESULT
	if (_container.size() != _sContainer.size())
		std::cout << "\033[1;31mERROR: SIZE DIFFERENT\033[0m" << std::endl;
	// VERIFY EACH VALUE IS BOTH IN ENTRY AND RESULT
	int res = 0;
	iter sIt = _sContainer.begin();
	for (; sIt != _sContainer.end(); ++sIt) {
		iter oIt = _container.begin();
		for (; oIt != _container.end(); ++oIt) {
			if (*oIt == *sIt) {
				res = 1;
				break;
			}
		}
		if (res != 1) {
			std::cout << "\033[1;31mERROR: SORTING\033[0m" << std::endl;
			return;
		}
		else
			res = 0;
	}
}
