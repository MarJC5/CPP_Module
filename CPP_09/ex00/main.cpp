#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input_file"  << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    exchange.loadData("data/data.csv");

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::string line, date;
    double value;
    std::getline(input, line);
    while (std::getline(input, line)) {
        if (exchange.parseInputLine(line, date, value)) {
            double price = exchange.getPrice(date);
            std::cout << date << " => " << value << " = " << price * value << std::endl;
        }
    }

    input.close();
    return 0;
}
