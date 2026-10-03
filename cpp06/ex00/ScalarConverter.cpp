#include "ScalarConverter.hpp"

#include <cctype>
#include <iomanip>
#include <iostream>

//int 42, -42, +42
//float 4.2f, -4.2f, .2f, 4.f
//double 4.2, -4.2, .2, 4.
//special +inff, -inff, nanf, +inf, -inf, nan

namespace
{
	enum LiteralType
	{
		SPECIAL,
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		INVALID
	};

	bool isDigit(char c)
	{
		if (c >= '0' && c <= '9')
			return(true);
		return(false);
	}

	bool isSpecial(const std::string& literal)
	{
		if(literal == "nanf" || literal == "+inff" || literal == "-inff"
			|| literal == "nan" || literal == "+inf" || literal == "-inf")
			return(true);
		return(false);
	}

	bool isChar(std::string& literal)
	{
		if(literal.size() != 1)
			return(false);

		unsigned char c = static_cast<unsigned char>(literal[0]);

		if(isDigit(literal[0]) == true)
			return(false);
		if(std::isprint(c) == false)
			return(false);

		return(true);
	}

	bool isInt(const std::string& literal)
	{
		//
		if(literal.empty())
			return(false);

		//This type stands for number of chars in std::string or location of std::string
		std::string::size_type i = 0;


	}
}
