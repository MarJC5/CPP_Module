#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <ctime>
#include <map>

/*
 * Map allows to store exchange rates for different dates and find the rate for a given date.
 * Each node contains a key, a value and pointers to the left and right nodes.
 * eg: 2017-01-01 is a key, 1000.0 is a value.
 */

class BitcoinExchange {
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		std::map<std::string, double> _data;
		std::string _fileName;

	public:
		BitcoinExchange(const std::string& fileName);
		virtual ~BitcoinExchange();

		double findValue(const std::string& date);
		void readData(const std::string& fileName);

		void getExchangeRate(const std::string& fileName);

};

#endif
