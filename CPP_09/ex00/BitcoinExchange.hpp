#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <ctime>
#include <map>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstdlib>

/*
 * Map allows to store exchange rates for different dates and find the rate for a given date.
 * Each node contains a key, a value and pointers to the left and right nodes.
 * eg: 2017-01-01 is a key, 1000.0 is a value.
 */

class BitcoinExchange
{
public:
	BitcoinExchange();
	virtual ~BitcoinExchange();

	void loadData(const std::string &filename);
	double getPrice(const std::string &date) const;

	bool isValidDate(const std::string &date);
	bool parseInputLine(const std::string &line, std::string &date, double &value);

private:
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	std::map<std::string, double> _priceData;
};

#endif