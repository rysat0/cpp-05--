#include "RPN.hpp"


RPN::RPN() : _numbers()
{
}

RPN::RPN(const RPN& other) : _numbers(other._numbers)
{
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN& other)
{
	if(this != &other)
		this->_numbers = other._numbers;
	return(*this);
}

void RPN::applyOperator(char operation)
{
	if(this->_numbers.size() < 2)
		throw std::runtime_error("Error: Not enough operands");

	double numRight = this->_numbers.top();
	this->_numbers.pop();

	double numLeft = this->_numbers.top();
	this->_numbers.pop();

	double result;

	switch(operation)
	{
		case '+':
			result = numLeft + numRight;
			break;

		case '-':
			result = numLeft - numRight;
			break;

		case '*':
			result = numLeft * numRight;
			break;

		case '/':
			if(numRight == 0)
				throw std::runtime_error("Error: division by zero.");

			result = numLeft / numRight;
			break;

		default:
			throw std::runtime_error("Error: Invalid operator");
	}
	const double max = std::numeric_limits<double>::max();
	if(!(result >= -max && result <= max))
		throw std::runtime_error("Error: numeric overflow");

	this->_numbers.push(result);

}

//pile up, lifo type

double RPN::evaluate(const std::string& expression)
{
	while(!this->_numbers.empty())
		this->_numbers.pop();

	std::istringstream stream(expression);
	std::string token;

	while(stream >> token) //前回の続きからwsを飛ばし次のwsまでの文字列をtokenへ入れる, 勝手にループ時に次へ進む
	{
		if(token.size() == 1 && (token[0] >= '0' && token[0] <= '9'))
			this->_numbers.push(token[0] - '0');
		else if(token == "+" || token == "-" || token == "*" || token == "/")
			applyOperator(token[0]);
		else
			throw std::runtime_error("Error: invalid token");
	}
	if(this->_numbers.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	return(this->_numbers.top());

}
