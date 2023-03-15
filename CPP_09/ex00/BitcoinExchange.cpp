#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& fileName): _fileName(fileName) {
	readData(fileName);
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::findValue(const std::string& date)
{
	std::map<std::string, double>::iterator it = _data.begin();
	for ( ; it != _data.end(); it++) {
		if (date > it->first)
			continue ;
		else
			break;
	}
	if (date != it->first)
		it--;
	return (it->second);
}

void BitcoinExchange::readData(const std::string& fileName) {
	std::string line;
	std::ifstream file;

	file.open(fileName.c_str());
	if (!file.is_open() || file.bad())
		throw std::bad_exception();
	std::getline(file, line);
	while (std::getline(file, line))
	{
		unsigned long pos = 0;
		std::string temp;
		if ((pos = line.find(',')) != std::string::npos)
		{
			temp = line.substr(0, pos);
			line.erase(0, pos + 1);
		}
		_data[temp] = std::atof(line.c_str());
	}
	file.close();
}

void BitcoinExchange::getExchangeRate(const std::string& fileName) {
	std::string line;
	std::ifstream file;

	std::time_t t = std::time(nullptr);
	std::tm tm = *std::localtime(&t);

	std::string y = std::to_string(tm.tm_year + 1900);
	std::string m = std::to_string(tm.tm_mon + 1);
	std::string j = std::to_string(tm.tm_mday);

	file.open(fileName.c_str());
	if (!file.is_open() || file.bad())
		throw std::bad_exception();
	std::getline(file, line);
	while (std::getline(file, line))
	{
		unsigned long pos;
		std::string temp;
		if ((pos = line.find(" | ")) != std::string::npos) {
			temp = line.substr(0, pos);
			line.erase(0, pos + 3);
		} else {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (y < temp.substr(0,4) || m < temp.substr(5, 2) || j < temp.substr(8, 2)) {
			std::cout << "Error: bad input => " << temp + " | " + line  << std::endl;
			continue ;
		}

		double d = std::atof(line.c_str());
		if (d < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (d > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
			std::cout << temp << " => " << d << " = " << findValue(temp) * d << std::endl;
	}
	file.close();
}