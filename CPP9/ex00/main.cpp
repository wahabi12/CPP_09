/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:52:53 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/30 02:18:45 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void processFile(const std::string& filePath, BitcoinExchange& btcExchange) {
	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		std::string valueStr;

		if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
			try {
				double value = std::stod(valueStr);
				if (!btcExchange.isValidDate(date)) {
					std::cerr << "Error: bad input => " << date << std::endl;
					continue;
				}
				if (!btcExchange.isValidValue(value)) {
					std::cerr << "Error: invalid value => " << value << std::endl;
					continue;
				}
				double result = btcExchange.calculateValue(date, value);
				std::cout << date << " => " << value << " = " << result << std::endl;
			} catch (const std::exception& e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
		} else {
			std::cerr << "Error: bad input format." << std::endl;
		}
	}

	file.close();
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btcExchange("data.csv");
		processFile(argv[1], btcExchange);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
