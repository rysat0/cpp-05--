#include "Span.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <exception>


void printSpans(const Span& sp)
{
	try
	{
		unsigned int shortest = sp.shortestSpan();
		std::cout << "Shortest: " << shortest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Shortest exception: " << e.what() << std::endl;
	}

	try
	{
		unsigned int longest = sp.longestSpan();
		std::cout << "Longest: " << longest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Longest exception: " << e.what() << std::endl;
	}
}


int main()
{

	std::cout << "----- Subject example test -----" << std::endl;

	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Excepted: shortest 2 / longest 14" << std::endl;
	printSpans(sp);



	std::cout << "\n----- addNumber overflow test -----" << std::endl;
	try
	{
		sp.addNumber(42);
		std::cout << "ERROR: exception was not thrown." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	printSpans(sp);



	std::cout << "\n----- Empty / One element test -----" << std::endl;
	Span smallSp(2);

	std::cout << "Empty: both should throw" << std::endl;
	printSpans(smallSp);

	smallSp.addNumber(42);
	std::cout << "One element: both should throw" << std::endl;
	printSpans(smallSp);



	std::cout << "\n----- Zero capacity test -----" << std::endl;
	Span zeroSp(0);
	try
	{
		zeroSp.addNumber(420);
		std::cout << "ERROR: exception was not thrown." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}



	std::cout << "\n----- Range / Negative numbers test -----" << std::endl;
	int nums[] = {-10, -3, 0, 8};
	Span rangeSp(5);

	rangeSp.addNumber(20);
	rangeSp.addNums(nums, nums + 4);
	std::cout << "Exception: shortest 3 / longest 30" << std::endl;
	printSpans(sp);


	return(0);
}
