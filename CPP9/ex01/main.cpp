/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:59:22 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/17 05:00:06 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <exception>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
		return 1;
	}

	try {
		std::string expression = argv[1];
		int result = RPN::evaluate(expression);
		std::cout << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
