#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <list>
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <iostream>
#include <exception>

class RPN
{
	private:
		std::stack<double, std::list<double> > _numbers;

		void applyOperator(char operation);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		double evaluate(const std::string& expression);
};


# endif
