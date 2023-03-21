#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        return false;
    }

    int year, month, day;
    if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
    {
        return false;
    }

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        return false;
    }

    return true;
}

bool BitcoinExchange::parseInputLine(const std::string &line, std::string &date, double &value)
{
    std::istringstream iss(line);
    char separator;

    if (!(iss >> date >> separator >> value)) // TODO: check if the input is not in the format "date <separator> value"
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }

    if (!isValidDate(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value > 1000)
    {
        std::cerr << "Error: too large number." << std::endl;
        return false;
    }

    return true;
}

void BitcoinExchange::loadData(const std::string &filename)
{
    std::string line;
    std::ifstream file;

    file.open(filename.c_str());
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
        _priceData[temp] = std::atof(line.c_str());
    }
    file.close();
}

double BitcoinExchange::getPrice(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _priceData.lower_bound(date); // returns the first element whose key is not less than date
    if (it == _priceData.end()) // date is after the last date in the map
    {
        return (--it)->second;
    }
    if (it == _priceData.begin()) // date is before the first date in the map
    {
        return it->second;
    }
    std::map<std::string, double>::const_iterator prev = it;
    --prev; // returns the previous element
    if (date.compare(prev->first) - date.compare(it->first) < 0)
    {
        return prev->second; // date is closer to prev than it
    }
    return it->second;
}
