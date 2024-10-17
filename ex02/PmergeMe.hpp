/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:34:52 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/17 05:02:09 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    PmergeMe(const std::vector<int>& sequence);
    
    void sortWithVector();

    void sortWithDeque();
    
    void printSequence(const std::string& prefix) const;

private:
    std::vector<int> vec;
    std::deque<int> deq;

    void printTime(double time, const std::string& containerType) const;

    void mergeInsertSortVector(std::vector<int>& arr, int left, int right);
    void mergeInsertSortDeque(std::deque<int>& arr, int left, int right);

    void insertionSort(std::vector<int>& arr, int left, int right);
    void insertionSort(std::deque<int>& arr, int left, int right);

    void merge(std::vector<int>& arr, int left, int mid, int right);
    void merge(std::deque<int>& arr, int left, int mid, int right);
};

#endif
