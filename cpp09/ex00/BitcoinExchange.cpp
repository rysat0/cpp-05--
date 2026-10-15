#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _rates()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates)
{
}

//std::map automatically deep copy
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if(this != &other)
		_rates = other._rates;
	return(*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

namespace
{
	std::string trimInput(const std::string& text)
	{

		const std::string whitespaces = " \t\r\n\v\f";

		std::string::size_type first;
		first = text.find_first_not_of(whitespaces);

		if(first == std::string::npos)
			return("");

		std::string::size_type last;
		last = text.find_last_not_of(whitespaces);

		return (text.substr(first, last - first + 1));
	}


	bool isValidDate(const std::string& date)
	{
		if(date.size() != 10 || date[4] != '-' || date[7] != '-')
		return(false);

		std::string::size_type i = 0;
		while (i < date.size())
		{
			if (i != 4 && i != 7)
			{
				if (date[i] < '0' || date[i] > '9')
					return (false);
			}
			++i;
		}

		int year;
		year = ((date[0] - '0') * 1000) +
				(date[1] - '0') * 100 +
				(date[2] - '0') * 10 +
				(date[3] - '0');

		int month = ((date[5] - '0') * 10) + (date[6] - '0');

		int day = ((date[8] - '0') * 10) + (date[9] - '0');

		if(year <= 0 || month < 1 || month > 12)
			return(false);

		int lastDayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		bool leapyear;
		leapyear = ((year % 400 == 0 )|| (year % 4 == 0 && year % 100 != 0));

		if(leapyear == true)
			lastDayOfMonth[1] = 29;

		bool isValid;

		isValid = (day >= 1 && day <= lastDayOfMonth[month - 1]);
		return(isValid);
	}


	bool parseNumber(const std::string& text, double& value)
	{
		std::istringstream stream(text);

		// if cant read nums, false
		// "stream >> value" -> skip ws before value, scan nums as double, put double nums to value, memorize success or false state to stream
		if(!(stream >> value))
			return(false);

		// skip ws
		// its same as std::ws(stream)
		stream >> std::ws;

		if(!stream.eof())
			return(false);

		const double max = std::numeric_limits<double>::max();

		if(value >= -max && value <= max)
			return(true);
		return(false);
	}
}

void BitcoinExchange::loadDatabase(const std::string& path)
{

	std::ifstream file(path.c_str());

	if(!file.is_open())
		throw std::runtime_error("Error: couldn't open database");

	std::string line;

	if(!std::getline(file, line) || trimInput(line) != "date,exchange_rate")
		throw std::runtime_error("Error: invalid database header");

	std::map<std::string, double> rates;

	while(std::getline(file, line))
	{
		std::string::size_type comma = line.find(',');

		if(comma == std::string::npos || line.find(',', comma + 1) != std::string::npos)
			throw std::runtime_error("Error: invalid database entry ->  " + line);

		std::string date = trimInput(line.substr(0, comma));
		std::string text = trimInput(line.substr(comma + 1));

		double rate;

		if(!isValidDate(date) || !parseNumber(text, rate) || rate < 0)
			throw std::runtime_error("Error: invalid database entry -> " + line);

		// date, rateをstd::string, double型としてmapに追加
		// .insert().firstは登録した要素やすでに存在していた場合はそれを示す
		// .insert().secondは新規登録成功でtrue, 重複（すでに同じキーあり）でfalseを返す
		if(!rates.insert(std::map<std::string, double>::value_type(date, rate)).second)
			throw std::runtime_error("Error: duplicate database date -> " + date);
	}

	//正常終了なら.fail() .eof()ともにtrue
	if (file.bad() || (file.fail() && !file.eof()))
		throw std::runtime_error("Error: could not read database.");

	if (rates.empty())
		throw std::runtime_error("Error: empty database.");

	this->_rates.swap(rates);
}

void BitcoinExchange::processFile(const std::string &path) const
{
	if(this->_rates.empty())
		throw std::runtime_error("Error: database is not loaded");

	std::ifstream file(path.c_str());

	if(!file.is_open())
		throw std::runtime_error("Error: couldn't open file");

	std::string line;
	bool firstLine = true;

	while(std::getline(file, line))
	{
		line = trimInput(line);
		if(firstLine == true)
		{
			firstLine = false;
			// skip first line(header)
			if(line == "date | value")
				continue;
		}
		processLine(line);
	}

	if(file.bad() || (file.fail() && !file.eof()))
		throw std::runtime_error("Error: couldn't read file");

	if(firstLine == true)
		std::cout << "Error: empty input file" << std::endl;
}

void BitcoinExchange::processLine(const std::string& line) const
{
	//一行の中で'|'の位置を指す
	std::string::size_type separator = line.find('|');

	//セパレータが一つもない、または二つ以上ある場合
	if(separator == std::string::npos || line.find('|', separator + 1) != std::string::npos)
	{
		std::cout << "Error: bad input -> " << line << std::endl;
		return;
	}

	std::string date = trimInput(line.substr(0, separator));
	std::string text = trimInput(line.substr(separator + 1));
	double value;

	if(!isValidDate(date) || !parseNumber(text, value))
	{
		std::cout << "Error: bad input -> " << line << std::endl;
		return;
	}

	if(value < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return;
	}
	else if(value > 1000)
	{
		std::cout << "Error: Number is too big" << std::endl;
		return;
	}

	std::map<std::string, double>::const_iterator it;
	it = this->_rates.upper_bound(date);

	if(it == this->_rates.begin())
	{
		std::cout << "Error: No exchange rate available -> " << date << std::endl;
		return;
	}

	--it;

	std::cout << date << " => " << value << " = " << value * it->second << std::endl;

}
