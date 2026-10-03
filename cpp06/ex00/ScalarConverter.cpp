#include "ScalarConverter.hpp"

#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <cmath>

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

	bool isChar(const std::string& literal)
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
		//this .empty() distinguish if literal was empty or not
		if(literal.empty())
			return(false);

		//This type stands for number of chars in std::string or location of std::string
		std::string::size_type i = 0;

		if(literal[i] == '+' || literal[i] == '-')
			++i;

		//if literal.size() == i, that means there is only + or - therefore false
		if(i == literal.size())
			return(false);

		while(i < literal.size())
		{
			if(isDigit(literal[i]) == false)
				return(false);
			++i;
		}
		return(true);
	}

	//make sure there are one dot and over one numbers
	bool isDecimal(const std::string& literal)
	{
		if(literal.empty())
			return(false);

		std::string::size_type i = 0;
		bool hasDot = false;
		bool hasDigit = false;

		if(literal[i] == '+' || literal[i] == '-')
			++i;

		while(i < literal.size())
		{
			if(isDigit(literal[i]))
				hasDigit = true;
			else if (literal[i] == '.' && hasDot == false)
				hasDot = true;
			else
				return(false);
			++i;
		}
		if(hasDot == true && hasDigit == true)
			return(true);
		return(false);
	}

	bool isFloat(const std::string& literal)
	{
		if(literal.empty())
			return(false);
		if(literal[literal.size() - 1] != 'f')
			return(false);

		if(isDecimal(literal.substr(0, literal.size() - 1)))
			return(true);
		return(false);
	}

	bool isDouble(const std::string& literal)
	{
		if(isDecimal(literal) == true)
			return(true);
		return(false);
	}

	LiteralType detectType(const std::string& literal)
	{
		if(isSpecial(literal))
			return(SPECIAL);
		if(isChar(literal))
			return(CHAR);
		if(isInt(literal))
			return(INT);
		if(isFloat(literal))
			return(FLOAT);
		if(isDouble(literal))
			return(DOUBLE);

		return(INVALID);
	}

	void convertSpecial(const std::string& literal)
	{
		float f;
		double d;

		if(literal[literal.size() - 1] == 'f')
		{
			if(literal == "nanf")
				f = std::numeric_limits<float>::quiet_NaN();
			else if(literal == "-inff")
				f = -(std::numeric_limits<float>::infinity());
			else
				f = std::numeric_limits<float>::infinity();

			d = static_cast<double>(f);
		}
		else
		{
			if(literal == "nan")
				d = std::numeric_limits<double>::quiet_NaN();
			else if(literal == "-inf")
				d = -(std::numeric_limits<double>::infinity());
			else
				d = std::numeric_limits<double>::infinity();

			f = static_cast<float>(d);
		}
		std::cout << "char: impossible\n" << "int: impossible\n"
			<< "float: " << f << "f\n" << "double: " << d << std::endl;
	}

	void convertChar(const std::string& literal)
	{
		char c = literal[0];

		int n = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);

		std::cout << "char: " << c << "f\n" << "int: " << n << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f\n" << "double: " << d << std::endl;
	}

	void convertInt(const std::string& literal)
	{
		std::istringstream input(literal);
		int n;

		if(!(input >> n))
		{
			std::cout << "char: impossible\n" << "int: impossible\n" << "float: impossible\n" << "double: impossible" << std::endl;
			return;
		}

		if(n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
			std::cout << "char: impossible\n";
		else
		{
			char c = static_cast<char>(n);
			char uc = static_cast<unsigned char>(n);

			if(std::isprint(uc))
				std::cout<<"char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}

		float f = static_cast<float>(n);
		double d = static_cast<double>(n);

		std::cout << "int: " << n << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f\n" << "double: " << d << std::endl;
	}

	void convertFloat(const std::string& literal)
	{
		//42.5f -> 42.5
		std::string num = literal.substr(0, literal.size() - 1);

		std::istringstream input(num);
		float f;

		if(!(input >> f))
		{
			std::cout << "char: impossible\n" << "int: impossible\n" << "float: impossible\n" << "double: impossible" << std::endl;
			return;
		}

		double d = static_cast<double>(f);
		double roundd;

		if(d < 0)
			roundd = std::ceil(d);
		else
			roundd = std::floor(d);

		//transfer to char
		if(roundd < std::numeric_limits<char>::min() || roundd > std::numeric_limits<char>::max())
			std::cout << "char: impossible" << std::endl;
		else
		{
			char c = static_cast<char>(f);

			if(std::isprint(static_cast<unsigned char>(c)))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}

		//transfer to int
		if(roundd < std::numeric_limits<int>::min() || roundd > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
		{
			int n = static_cast<int>(f);
			std::cout << "int: " << n << std::endl;
		}

		if(d == roundd)
		{
			std::cout << std::fixed << std::setprecision(1);
		}
		else
		{
			std::cout.unsetf(std::ios::floatfield);
			std::cout << std::setprecision(std::numeric_limits<float>::digits10);
		}

		std::cout << "float: " << f << "f\n" << "double: " << d << std::endl;
	}

	std::string formatFloating(double value, int precision)
	{
		std::ostringstream output;

		output << std::setprecision(precision) << value;

		std::string result = output.str();

		if(result.find_first_of(".eE") == std::string::npos)
			result += ".0";

		return (result);
	}

	void convertDouble(const std::string& literal)
	{
		std::istringstream input(literal);
		double d;

		if(!(input >> d))
		{
			std::cout << "char: impossible\n" << "int: impossible\n" << "float: impossible\n" << "double: impossible" << std::endl;
			return;
		}

		double roundd;

		if(d < 0)
			roundd = std::ceil(d);
		else
			roundd = std::floor(d);

		//char
		if(roundd < std::numeric_limits<char>::min() || roundd > std::numeric_limits<char>::max())
			std::cout << "char: impossible" << std::endl;
		else
		{
			char c = static_cast<char>(d);

			if(std::isprint(static_cast<unsigned char>(c)))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}

		//int
		if(roundd < std::numeric_limits<int>::min() || roundd > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
		{
			int n = static_cast<int>(d);
			std::cout << "int: " << n << std::endl;
		}

		//float
		if(d < -(std::numeric_limits<float>::max()) || d > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
		{
			float f = static_cast<float>(d);

			std::cout << "float: " << formatFloating(f, std::numeric_limits<float>::digits10) << "f" << std::endl;
		}
		//double
		std::cout << "double: " << formatFloating(d, std::numeric_limits<double>::digits10) << std::endl;

	}

}


void ScalarConverter::convert(const std::string& literal)
{
	LiteralType type = detectType(literal);

	switch(type)
	{
		case SPECIAL:
			convertSpecial(literal);
			break;

		case CHAR:
			convertChar(literal);
			break;

		case INT:
			convertInt(literal);
			break;

		case FLOAT:
			convertFloat(literal);
			break;

		case DOUBLE:
			convertDouble(literal);
			break;

		case INVALID:
			std::cout << "char: impossible\n" << "int: impossible\n" << "float: impossible\n" << "double: impossible" << std::endl;
			break;
	}
}
