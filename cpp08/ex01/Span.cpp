#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <stdexcept>



Span::Span() : N(0), _nums()
{
}

Span::Span(unsigned int cap) : N(cap), _nums()
{
}

Span::Span(const Span& other) : N(other.N), _nums(other._nums)
{
}

Span& Span::operator=(const Span& other)
{
	if(this != &other)
	{
		this->N = other.N;
		this->_nums = other._nums;
	}
	return(*this);
}

Span::~Span()
{
}

void Span::addNumber(int addRequestedNum)
{
	if(this->_nums.size() >= this->N)
		throw std::overflow_error("Span is full");

	this->_nums.push_back(addRequestedNum);
}

unsigned int Span::shortestSpan() const
{
	//comparison needs at least 2 elements
	if(this->_nums.size() < 2)
		throw std::logic_error("Not enough numbers");

	//copy nums to another vector
	std::vector<int> copyNums(this->_nums);

	//sort copied vec
	std::sort(copyNums.begin(), copyNums.end());

	unsigned int shortest = UINT_MAX;
	std::vector<int>::size_type i = 1;
	unsigned int currentSpan = 0;

	//check diff to num next to now
	while(i < copyNums.size())
	{
		currentSpan = static_cast<unsigned int>(copyNums[i]) - static_cast<unsigned int>(copyNums[i - 1]);
		shortest = std::min(shortest, currentSpan);
		i++;
	}
	return(shortest);
}

unsigned int Span::longestSpan() const
{
	if(this->_nums.size() < 2)
		throw std::logic_error("Not enough numbers");

	unsigned int longest;

	int minValue = *std::min_element(this->_nums.begin(), this->_nums.end());
    int maxValue = *std::max_element(this->_nums.begin(), this->_nums.end());

	longest = static_cast<unsigned int>(maxValue) - static_cast<unsigned int>(minValue);

	return(longest);
}

/*
 int minValue = *std::min_element(this->_nums.begin(), this->_nums.end());
 int maxValue = *std::max_element(this->_nums.begin(), this->_nums.end());
	std::min/max_element return "iterator" so add '*' so that we can use it as number
*/
