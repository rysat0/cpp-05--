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

	std::cout << "Expected: shortest 2 / longest 14" << std::endl;
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
	std::cout << "Expected: shortest 3 / longest 30" << std::endl;
	printSpans(rangeSp);



	std::cout << "\n----- Empty range on full span test -----" << std::endl;
	rangeSp.addNums(nums, nums);
	std::cout << "Expected: unchanged, shortest 3 / longest 30" << std::endl;
	printSpans(rangeSp);




	std::cout << "\n----- Range overflow test -----" << std::endl;
	Span limitedSp(3);
	limitedSp.addNumber(10);
	limitedSp.addNumber(20);

	int extra[] = {-100, 100};
	try
	{
		limitedSp.addNums(extra, extra + 2);
		std::cout << "ERROR: exception was not thrown." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "Expected: unchanged, shortest 10 / longest 10" << std::endl;
	printSpans(limitedSp);

	limitedSp.addNumber(15);
	std::cout << "Expected: remaining space usable, shortest 5 / longest 10" << std::endl;
	printSpans(limitedSp);



	std::cout << "\n----- List / Duplicate numbers test -----" << std::endl;
	std::list<int> numList;
	numList.push_back(7);
	numList.push_back(7);
	numList.push_back(7);

	Span duplicateSp(3);
	duplicateSp.addNums(numList.begin(), numList.end());
	std::cout << "Expected: shortest 0 / longest 0" << std::endl;
	printSpans(duplicateSp);


	std::cout << "\n----- INT_MIN / INT_MAX test -----" << std::endl;
	Span numLimitsSp(2);

	numLimitsSp.addNumber(INT_MIN);
	numLimitsSp.addNumber(INT_MAX);

	std::cout << "Expected: " << "shortest and longest " << UINT_MAX << std::endl;
	printSpans(numLimitsSp);



	std::cout << "\n----- Copy constructor / Assignment test -----" << std::endl;
	Span originalSp(3);
	originalSp.addNumber(10);
	originalSp.addNumber(20);

	Span copiedSp(originalSp);
	Span assignedSp;

	assignedSp = originalSp;

	originalSp.addNumber(11);
	copiedSp.addNumber(30);
	assignedSp.addNumber(-10);

	std::cout << "Original expected: shortest 1 / longest 10" << std::endl;
	printSpans(originalSp);

	std::cout << "Copy expected: shortest 10 / longest 20" << std::endl;
	printSpans(copiedSp);

	std::cout << "Assigned expected: shortest 10 / longest 30" << std::endl;
	printSpans(assignedSp);



	std::cout << "\n----- 10,000 numbers test -----" << std::endl;
	std::vector<int> hugeNums;
	int i = 10000;

	while(i > 0)
	{
		hugeNums.push_back(i * 2);
		--i;
	}

	Span large(10000);
	large.addNums(hugeNums.begin(), hugeNums.end());
	std::cout << "Expected: shortest 2 / longest 19998" << std::endl;
	printSpans(large);

	return(0);
}
