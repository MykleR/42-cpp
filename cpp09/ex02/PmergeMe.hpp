/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:06:57 by mykle             #+#    #+#             */
/*   Updated: 2025/05/28 21:14:19 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <algorithm>

template<typename Container>
class PmergeMe {
private:
    using value_type = typename Container::value_type;
    
    struct Pair {
        value_type larger;
        value_type smaller;
        size_t originalIndex;
    };
    
    static std::vector<size_t> generateJacobsthal(size_t n) {
        std::vector<size_t> sequence;
        if (n == 0) return sequence;
        
        sequence.push_back(1);
        if (n == 1) return sequence;
        
        size_t prev = 0, curr = 1;
        while (curr < n) {
            size_t next = curr + 2 * prev;
            if (next > n) break;
            sequence.push_back(next);
            prev = curr;
            curr = next;
        }
        return sequence;
    }
    
    static size_t binaryInsertPos(const Container& sorted, const value_type& value, size_t limit) {
        size_t left = 0;
        size_t right = std::min(limit, sorted.size());
        
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (sorted[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    static Container fordJohnsonSort(const Container& input) {
        size_t n = input.size();
        
        if (n <= 1) {
            return input;
        }
        
        if (n == 2) {
            Container result = input;
            if (result[0] > result[1]) {
                std::swap(result[0], result[1]);
            }
            return result;
        }
        
        std::vector<Pair> pairs;
        value_type straggler;
        bool hasStraggler = (n % 2 == 1);
        
        for (size_t i = 0; i < n / 2; ++i) {
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
        
        if (hasStraggler) {
            straggler = input[n - 1];
        }
        
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
