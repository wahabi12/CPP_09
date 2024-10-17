/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:35:05 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/17 05:01:45 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>
#include <algorithm>

PmergeMe::PmergeMe(const std::vector<int>& sequence) : vec(sequence), deq(sequence.begin(), sequence.end()) {}

void PmergeMe::sortWithVector() {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	
	mergeInsertSortVector(vec, 0, vec.size() - 1);
	
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	printTime(elapsed.count(), "std::vector");
}

void PmergeMe::sortWithDeque() {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	
	mergeInsertSortDeque(deq, 0, deq.size() - 1);
	
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	printTime(elapsed.count(), "std::deque");
}

void PmergeMe::printSequence(const std::string& prefix) const {
	std::cout << prefix;
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printTime(double time, const std::string& containerType) const {
	std::cout << "Time to process a range of " << vec.size() << " elements with " << containerType << ": " << time << " us" << std::endl;
}

void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}
void PmergeMe::insertionSort(std::deque<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> leftArr(n1);
	std::vector<int> rightArr(n2);

	for (int i = 0; i < n1; ++i)
		leftArr[i] = arr[left + i];
	for (int j = 0; j < n2; ++j)
		rightArr[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			++i;
		} else {
			arr[k] = rightArr[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		arr[k] = leftArr[i];
		++i;
		++k;
	}

	while (j < n2) {
		arr[k] = rightArr[j];
		++j;
		++k;
	}
}

void PmergeMe::merge(std::deque<int>& arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<int> leftArr(n1);
	std::deque<int> rightArr(n2);

	for (int i = 0; i < n1; ++i)
		leftArr[i] = arr[left + i];
	for (int j = 0; j < n2; ++j)
		rightArr[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			++i;
		} else {
			arr[k] = rightArr[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		arr[k] = leftArr[i];
		++i;
		++k;
	}

	while (j < n2) {
		arr[k] = rightArr[j];
		++j;
		++k;
	}
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr, int left, int right) {
	if (left < right) {
		if (right - left <= 10) {
			insertionSort(arr, left, right);
		} else {
			int mid = left + (right - left) / 2;
			mergeInsertSortVector(arr, left, mid);
			mergeInsertSortVector(arr, mid + 1, right);
			merge(arr, left, mid, right);
		}
	}
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr, int left, int right) {
	if (left < right) {
		if (right - left <= 10) {
			insertionSort(arr, left, right);
		} else {
			int mid = left + (right - left) / 2;
			mergeInsertSortDeque(arr, left, mid);
			mergeInsertSortDeque(arr, mid + 1, right);
			merge(arr, left, mid, right);
		}
	}
}
