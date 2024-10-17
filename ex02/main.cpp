/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:34:13 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/17 05:01:06 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Error: no input provided" << std::endl;
		return 1;
	}

	std::vector<int> sequence;
	try {
		for (int i = 1; i < argc; ++i) {
			int num = std::stoi(argv[i]);
			if (num < 0) {
				throw std::invalid_argument("Error: negative number");
			}
			sequence.push_back(num);
		}
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	PmergeMe sorter(sequence);
	
	sorter.printSequence("Before: ");
	
	sorter.sortWithVector();
	sorter.printSequence("After (vector): ");
	
	sorter.sortWithDeque();
	sorter.printSequence("After (deque): ");

	return 0;
}
