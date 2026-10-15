#include "RPN.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error: Invalid argv.\nUsage: ./RPN \"expression\"" << std::endl;
		return(1);
	}
	try
	{
		RPN calculator;
		double result = calculator.evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
		return(1);
	}
	return(0);
}
