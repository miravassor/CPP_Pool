/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeMergeMe.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:00:03 by avassor           #+#    #+#             */
/*   Updated: 2023/12/12 15:25:59 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeMergeMe.hpp"
#include "vectorMergeMe.hpp"

// Build

template <typename Container>
dequeMergeMe<Container>::dequeMergeMe(dequeMergeMe<Container>& tocopy) {
	*this = tocopy;
}

template <typename Container>
dequeMergeMe<Container>&	dequeMergeMe<Container>::operator=(const dequeMergeMe<Container> &rhs) {
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
void	dequeMergeMe<Container>::run(int argc, char **argv) {
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
	printInit();
	_timeStart = microTime();
	makePair();
	insert(_pairContainer.size() - 1);
	pushSorted();
	jacobsthal();
	insertPend();
	_timeEnd = microTime();
	// verifySort();
	printResult();

	vectorMergeMe<std::vector<int> > vec;
	vec.run(argc, argv);
}

// make pairs of values, leaving one element if odd entry
// sort the pair (a < b) if needed and push to a container of pairs
template <typename Container>
void	dequeMergeMe<Container>::makePair() {
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

// recursive insertion sort for each largest pair value
// first index is considered sorted
template <typename Container>
void	dequeMergeMe<Container>::insert(int index) {
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

// push sorted largest value to final container
// push unsorted lower value to pending container
// push first value from pending to beginning of final container
template <typename Container>
void	dequeMergeMe<Container>::pushSorted() {
	for (long unsigned int i = 0; i != _pairContainer.size(); ++i) {
		_sContainer.push_back(_pairContainer[i].second);
		_pendContainer.push_back(_pairContainer[i].first);
	}
	_sContainer.push_front(*_pendContainer.begin());
	_pendContainer.pop_front();
}

// insertion of remaining elements in pend to final container
// uses previously generated jacobsthal to compute mid point in the binary search
// minimizing comparisons
// handle odd element if present
template <typename Container>
void	dequeMergeMe<Container>::insertPend() {
	while (!_pendContainer.empty()) {
		iter	start = _sContainer.begin();
		iter	end = _sContainer.end();
		if (_jacobContainer.empty() || static_cast<long unsigned int>(_jacobContainer.front()) > _sContainer.size()) {
			binarySearch(_pendContainer.begin(), start, end, 0);
			_pendContainer.pop_front();
		}
		else {
			int	index = *_jacobContainer.begin() - 1;
			binarySearch(_pendContainer.begin(), start, end, index);
			_pendContainer.pop_front();
			_jacobContainer.pop_front();
		}
	}
	if (_container.size() % 2 != 0) {
		iter	start = _sContainer.begin();
		iter	end = _sContainer.end();
		binarySearch((_container.end() - 1), start, end, 0);
	}
}

template <typename Container>
void	dequeMergeMe<Container>::binarySearch(iter key, iter start, iter end, int index) {
	if (start >= end)
		return;
	if (*key < *_sContainer.begin()) {
		_sContainer.push_front(*key);
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

// Utils

template <typename Container>
bool	dequeMergeMe<Container>::findDuplicate(int input) {
	for (iter it = _container.begin(); it != _container.end(); ++it) {
		if (*it == input)
			return 1;
	}
	return 0;
}

template <typename Container>
void	dequeMergeMe<Container>::printInit() {
	std::cout << "\033[1;32mBefore:\t\033[0m";
	iter	deq = _container.begin();
	for (; deq != _container.end(); ++deq) {
		std::cout << *deq;
		if (deq + 1 != _container.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

// Print

template <typename Container>
void	dequeMergeMe<Container>::printResult() {
	std::cout << "\033[1;32mAfter:\t\033[0m";
	std::deque<int>::iterator	dq = _sContainer.begin();
	for (; dq != _sContainer.end(); ++dq) {
		std::cout << *dq;
		if (dq + 1 != _sContainer.end())
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _container.size();
	std::cout << " elements with std::deque: ";
	std::cout << std::fixed << std::setprecision(6) << _timeEnd - _timeStart;
	std::cout << " seconds" << std::endl;
}

template <typename Container>
void dequeMergeMe<Container>::verifySort() {
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
