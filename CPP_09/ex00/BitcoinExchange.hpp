#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
#include <ctime>

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
