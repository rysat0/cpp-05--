#include "BitcoinExchange.hpp"

#include <exception>
#include <iostream>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cout << "Error: invalid argv.\nUsage: ./btc <file>" << std::endl;
		return(1);
	}

	try
	{
		BitcoinExchange exchange;

		exchange.loadDatabase("data.csv");
		exchange.processFile(argv[1]);
	}
	catch(const std::exception& error)
	{
		std::cout << error.what() << std::endl;
		return(1);
	}
	
	return(0);
}
