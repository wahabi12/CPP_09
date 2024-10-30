/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:54:00 by blatifat          #+#    #+#             */
/*   Updated: 2024/10/30 01:36:35 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <limits>

class BitcoinExchange {
public:
	BitcoinExchange(const std::string& dbFilePath);

	double calculateValue(const std::string& date, double amount);

	void loadDatabase(const std::string& dbFilePath);

	std::string findClosestDate(const std::string& date);

	bool isValidDate(const std::string& date);
	bool isValidValue(double value);

private:
	std::map<std::string, double> btcPrices;
};

#endif

