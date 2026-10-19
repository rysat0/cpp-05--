#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
	try
	{
			PmergeMe sorter;
			sorter.run(argc, argv);
	}
	catch(const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
		return(1);
	}
	return(0);
}


/*
std::vector<int>
std::deque<int>
*/
