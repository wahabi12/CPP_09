/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:00:21 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/17 05:00:44 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int applyOperator(int a, int b, char op) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': 
			if (b == 0) {
				throw std::runtime_error("Error: division by zero");
			}
			return a / b;
		default: throw std::runtime_error("Error: invalid operator");
	}
}


int RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token) {
		if (isdigit(token[0])) {
			stack.push(std::atoi(token.c_str()));
		}
		else if (token.length() == 1 && isOperator(token[0])) {
			if (stack.size() < 2) {
				throw std::runtime_error("Error: invalid expression");
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

			int result = applyOperator(a, b, token[0]);
			stack.push(result);
		}
		else {
			throw std::runtime_error("Error: invalid token in expression");
		}
	}
	if (stack.size() != 1) {
		throw std::runtime_error("Error: invalid expression");
	}

	return stack.top();
}
