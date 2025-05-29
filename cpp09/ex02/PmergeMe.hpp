/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:06:57 by mykle             #+#    #+#             */
/*   Updated: 2025/05/29 13:17:12 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>

template<typename Container> class PmergeMe
{
public:
	static Container sort(const Container& container)
	{
		return fordJohnsonSort(container);
	}

private:
	PmergeMe() = delete;
	~PmergeMe() = delete;
	PmergeMe(const PmergeMe&) = delete;
	PmergeMe& operator=(const PmergeMe&) = delete;

	typedef typename Container::value_type value_type;
	typedef struct s_pair {
		value_type larger;
		value_type smaller;
		size_t originalIndex;
	} Pair;

	static Container fordJohnsonSort(const Container& input);

	static std::vector<size_t> generateJacobsthal(size_t n);
	static void binaryInsertPos(Container& sorted, const value_type& value, size_t limit);
	static size_t findWinnerPos(const Container& sortedWinners, const value_type& winner);
	static void createPairs(const Container& input, std::vector<Pair>& pairs);
	static Container extractWinners(const std::vector<Pair>& pairs);

	static void buildWinnerMapping(const Container& sortedWinners, const std::vector<Pair>& pairs, 
			std::vector<size_t>& winnerToOriginalIndex);
    
	static Container initMain(const Container& sortedWinners, const std::vector<Pair>& pairs,
            const std::vector<size_t>& winnerToOriginalIndex);

	static void insertJacobOrder(Container& main, const std::vector<Pair>& pairs,
			const Container& sortedWinners, const std::vector<size_t>& indexes,
			std::vector<bool>& inserted);

	static void insertRemaining(Container& main, const std::vector<Pair>& pairs,
			const Container& sortedWinners, const std::vector<size_t>& indexes,
			std::vector<bool>& inserted);
};

//  ====================================
//  ========== Implementation ==========

template<typename Container>
Container PmergeMe<Container>::fordJohnsonSort(const Container& input)
{
	if (input.size() <= 1) return input; 
	// Step 1: Create pairs
	std::vector<Pair> pairs;
	createPairs(input, pairs);
	// Step 2: Extract winners and sort them recursively
	Container sortedWinners = fordJohnsonSort(extractWinners(pairs));
	// Step 3: Build mapping from sorted winners to original pair indices
	std::vector<size_t> indexes;
	buildWinnerMapping(sortedWinners, pairs, indexes);
	// Step 4: Initialize main chain with first smaller element and all winners
	Container main = initMain(sortedWinners, pairs, indexes);
	// Step 5: Insert remaining smaller elements using Jacobsthal sequence
	std::vector<bool> inserted(pairs.size(), false);
	inserted[0] = true;
	insertJacobOrder(main, pairs, sortedWinners, indexes, inserted);
	insertRemaining(main, pairs, sortedWinners, indexes, inserted);
	// Step 6: Insert straggler if it exists
	if (input.size() % 2)
		binaryInsertPos(main, input[input.size() - 1], main.size());

	return main;
}

template<typename Container>
void PmergeMe<Container>::createPairs(const Container& input, std::vector<Pair>& pairs)
{
	size_t n = input.size();
	for (size_t i = 0; i < n / 2; ++i)
		pairs.push_back({
			std::max(input[i * 2], input[i * 2 + 1]),
			std::min(input[i * 2], input[i * 2 + 1]), i});
}

template<typename Container>
Container PmergeMe<Container>::extractWinners(const std::vector<Pair>& pairs)
{
	Container winners;
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].larger);
	return winners;
}


template<typename Container>
std::vector<size_t> PmergeMe<Container>::generateJacobsthal(size_t n)
{
	std::vector<size_t> sequence;
	sequence.push_back(0);
	sequence.push_back(1);
	size_t prev = 0, curr = 1;
	while (curr < n) {
		sequence.push_back(curr);
		prev = curr;
		curr += (prev << 1);
	}
	return sequence;
}

template<typename Container>
void PmergeMe<Container>::binaryInsertPos(Container& sorted,
		const value_type& value, size_t limit)
{
	size_t left=0, right=std::min(limit, sorted.size());

	while (left < right) {
		size_t mid = left + ((right - left) >> 1);
		left = (sorted[mid] < value) ? mid + 1 : left;
		right = (sorted[mid] < value) ? right : mid;
	}
	sorted.insert(sorted.begin() + left, value);
}

template<typename Container>
void PmergeMe<Container>::buildWinnerMapping(const Container& sortedWinners,
		const std::vector<Pair>& pairs, 
		std::vector<size_t>& winnerToOriginalIndex)
{
	winnerToOriginalIndex.resize(sortedWinners.size());
	for (size_t i = 0; i < sortedWinners.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (pairs[j].larger == sortedWinners[i]) {
				winnerToOriginalIndex[i] = j;
				break;
			}
		}
	}
}

template<typename Container>
Container PmergeMe<Container>::initMain(const Container& sortedWinners,
		const std::vector<Pair>& pairs,
		const std::vector<size_t>& winnerToOriginalIndex)
{
	Container main;
	main.push_back(pairs[winnerToOriginalIndex[0]].smaller);

	for (size_t i = 0; i < sortedWinners.size(); ++i)
		main.push_back(sortedWinners[i]);
	return main;
}

template<typename Container>
size_t PmergeMe<Container>::findWinnerPos(const Container& sortedWinners,
		const value_type& winner)
{
	for (size_t k = 0; k < sortedWinners.size(); ++k)
		if (sortedWinners[k] == winner)
			return k + 1;
	return 0;
}

template<typename Container>
void PmergeMe<Container>::insertJacobOrder(Container& main, const std::vector<Pair>& pairs,
		const Container& sortedWinners, const std::vector<size_t>& indexes,
		std::vector<bool>& inserted)
{
	std::vector<size_t> jacobsthal = generateJacobsthal(pairs.size());

	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		size_t end = jacobsthal[i] - 1;
		size_t start = (i == 0) ? 0 : jacobsthal[i - 1];

		for (size_t j = end; j && j >= start && j < pairs.size(); --j) {
			if (!inserted[j]) {
				size_t pos = findWinnerPos(sortedWinners, pairs[indexes[j]].larger);
				size_t count = std::accumulate(inserted.begin(), inserted.begin() + j, 0);
				size_t searchLimit = pos + count + 1;

				binaryInsertPos(main, pairs[indexes[j]].smaller, searchLimit);
				inserted[j] = true;
			}
		}
	}
}

template<typename Container>
void PmergeMe<Container>::insertRemaining(Container& main, const std::vector<Pair>& pairs,
		const Container& sortedWinners, const std::vector<size_t>& indexes,
		std::vector<bool>& inserted)
{
	for (size_t i = 1; i < pairs.size(); ++i) {
		if (!inserted[i]) {
			size_t pos = findWinnerPos(sortedWinners, pairs[indexes[i]].larger);
			size_t count = std::accumulate(inserted.begin(), inserted.begin() + i, 0);
			size_t searchLimit = pos + count + 1;

			binaryInsertPos(main, pairs[indexes[i]].smaller, searchLimit);
			inserted[i] = true;
		}
	}
}


