#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>


class BitcoinExchange
{
	private:
		std::map<std::string, double> _rates;

		void processLine(const std::string& line) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadDatabase(const std::string& path);
		void processFile(const std::string &path) const;
};

#endif
