/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:54:20 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/30 01:36:45 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dbFilePath) {
	loadDatabase(dbFilePath);
}

void BitcoinExchange::loadDatabase(const std::string& dbFilePath) {
	std::ifstream file(dbFilePath);
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open file.");
	}

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		double price;

		if (std::getline(ss, date, ',') && ss >> price) {
			btcPrices[date] = price;
		}
	}
	file.close();
}

double BitcoinExchange::calculateValue(const std::string& date, double amount) {
	if (!isValidValue(amount)) {
		throw std::runtime_error("Error: invalid value.");
	}

	std::string closestDate = findClosestDate(date);
	return btcPrices[closestDate] * amount;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {
	std::map<std::string, double>::iterator it = btcPrices.lower_bound(date);
	if (it == btcPrices.end() || it->first != date) {
		if (it != btcPrices.begin()) {
			--it;
		}
	}
	return it->first;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	std::tm tm = {};
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	return !ss.fail();
}

bool BitcoinExchange::isValidValue(double value) {
	return (value >= 0 && value <= 1000);
}
