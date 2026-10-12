#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>

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

}


#endif
