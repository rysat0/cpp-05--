#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

class Span
{
	private:
		unsigned int N;
		std::vector<int> _nums;

	public:
		Span();
		~Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);

		void addNumber(int addRequestedNum);

		template <typename It>
		void addNums(It first, It last);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

};

template <typename It>
void Span::addNums(It first, It last)
{
	std::vector<int> incomingVector(first, last);

	if(incomingVector.size() > (this->N - this->_nums.size()))
		throw std::overflow_error("Span doesn't have enough space");

	//arg1. beginning position to be added
	//arg2. beginning position of Array that is going to add
	//arg3. end position of Array that is going to add
	this->_nums.insert(this->_nums.end(), incomingVector.begin(), incomingVector.end());
}


#endif
