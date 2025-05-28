/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:06:57 by mykle             #+#    #+#             */
/*   Updated: 2025/05/29 00:03:52 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <algorithm>

template<typename Container>
class PmergeMe {
private:
	typedef typename Container::value_type value_type; 
    typedef struct s_pair {
        value_type larger;
        value_type smaller;
        size_t originalIndex;
    } Pair;
    
    static std::vector<size_t> generateJacobsthal(size_t n)
	{
        std::vector<size_t> sequence;
        sequence.push_back(0);
        sequence.push_back(1); 
        size_t prev = 0, curr = 1;
        while (curr < n) {
            sequence.push_back(curr);
            prev = curr;
            curr = curr + 2 * prev;
        }
        return sequence;
    }
    
    static size_t binaryInsertPos(const Container& sorted, const value_type& value, size_t limit)
	{
        size_t left=0, right=std::min(limit, sorted.size());
        
        while (left < right) {
            size_t mid = left + (right - left) / 2;
			left = (sorted[mid] < value) ? mid + 1 : left;
			right = (sorted[mid] < value) ? right : mid;
        }
        return left;
    }

	static Container fordJohnsonSort(const Container& input)
	{
        if (input.size() <= 1) return input;
        
        std::vector<Pair> pairs;
        value_type straggler;
        bool hasStraggler = (input.size() % 2 == 1);
        
        for (size_t i = 0; i < input.size() / 2; ++i) {
            Pair p;
            if (input[i * 2] > input[i * 2 + 1]) {
                p.larger = input[i * 2];
                p.smaller = input[i * 2 + 1];
            } else {
                p.larger = input[i * 2 + 1];
                p.smaller = input[i * 2];
            }
            p.originalIndex = i;
            pairs.push_back(p);
        }
        
        if (hasStraggler)
            straggler = input[input.size() - 1];
        
        Container winners;
        for (size_t i = 0; i < pairs.size(); ++i) {
            winners.push_back(pairs[i].larger);
        }
        
        Container sortedWinners = fordJohnsonSort(winners);
        
        std::vector<size_t> winnerToOriginalIndex(sortedWinners.size());
        for (size_t i = 0; i < sortedWinners.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].larger == sortedWinners[i]) {
                    winnerToOriginalIndex[i] = j;
                    break;
                }
            }
        }
        
        Container mainChain;
        mainChain.push_back(pairs[winnerToOriginalIndex[0]].smaller);
        
        for (size_t i = 0; i < sortedWinners.size(); ++i) {
            mainChain.push_back(sortedWinners[i]);
        }
        
        std::vector<size_t> jacobsthal = generateJacobsthal(pairs.size());
        std::vector<bool> inserted(pairs.size(), false);
        inserted[0] = true;
        
        for (size_t i = 0; i < jacobsthal.size(); ++i) {
            size_t end = jacobsthal[i] - 1;
            size_t start = (i == 0) ? 1 : jacobsthal[i - 1];
            
            for (size_t j = end; j >= start && j < pairs.size(); --j) {
                if (!inserted[j]) {
                    size_t winnerPos = 0;
                    for (size_t k = 0; k < sortedWinners.size(); ++k) {
                        if (sortedWinners[k] == pairs[winnerToOriginalIndex[j]].larger) {
                            winnerPos = k + 1;
                            break;
                        }
                    }
                    
                    size_t insertedCount = 0;
                    for (size_t k = 0; k < j; ++k) {
                        if (inserted[k]) insertedCount++;
                    }
                    
                    size_t searchLimit = winnerPos + insertedCount + 1;
                    size_t pos = binaryInsertPos(mainChain, pairs[winnerToOriginalIndex[j]].smaller, searchLimit);
                    mainChain.insert(mainChain.begin() + pos, pairs[winnerToOriginalIndex[j]].smaller);
                    inserted[j] = true;
                }
                if (j == 0) break;
            }
        }
        
        for (size_t i = 1; i < pairs.size(); ++i) {
            if (!inserted[i]) {
                size_t winnerPos = 0;
                for (size_t k = 0; k < sortedWinners.size(); ++k) {
                    if (sortedWinners[k] == pairs[winnerToOriginalIndex[i]].larger) {
                        winnerPos = k + 1;
                        break;
                    }
                }
                
                size_t insertedCount = 0;
                for (size_t k = 0; k < i; ++k) {
                    if (inserted[k]) insertedCount++;
                }
                
                size_t searchLimit = winnerPos + insertedCount + 1;
                size_t pos = binaryInsertPos(mainChain, pairs[winnerToOriginalIndex[i]].smaller, searchLimit);
                mainChain.insert(mainChain.begin() + pos, pairs[winnerToOriginalIndex[i]].smaller);
                inserted[i] = true;
            }
        }
        
        if (hasStraggler) {
            size_t pos = binaryInsertPos(mainChain, straggler, mainChain.size());
            mainChain.insert(mainChain.begin() + pos, straggler);
        }
        
        return mainChain;
    }

public:
    static Container sort(const Container& container) {
        return fordJohnsonSort(container);
    }
};
