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
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return(0);
}
