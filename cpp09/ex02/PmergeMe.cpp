#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(), _deque()
{
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if(this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return(*this);
}

PmergeMe::~PmergeMe()
{
}


namespace
{
	int parsePositiveInteger(const std::string& text)
	{
		if(text.empty())
			throw std::runtime_error("Error: empty argument");

		int value = 0;
		std::string::size_type i = 0;

		while(i < text.size())
		{
			if(text[i] < '0' || text[i] > '9')
				throw std::runtime_error("Error: invalid input");

				int digit = text[i] - '0';

				if(value > (INT_MAX - digit) / 10)
					throw std::runtime_error("Error: integer overflow");

				value = value * 10 + digit;
				++i;
		}
		if(value == 0)
			throw std::runtime_error("Error: value must be positive");

		return(value);
	}

}






void PmergeMe::sortVector()
{

}
void PmergeMe::sortDeque()
{

}

void PmergeMe::loadVector(int argc, char **argv)
{
	this->_vector.clear();
	int i = 1;
	int value = 0;

	while(i < argc)
	{
		value = parsePositiveInteger(argv[i]);
		this->_vector.push_back(value);
		++i;
	}
}
void PmergeMe::loadDeque(int argc, char **argv)
{
	this->_deque.clear();
	int i = 1;
	int value = 0;

	while(i < argc)
	{
		value = parsePositiveInteger(argv[i]);
		this->_deque.push_back(value);
		++i;
	}
}

void PmergeMe::run(int argc, char **argv)
{
}
