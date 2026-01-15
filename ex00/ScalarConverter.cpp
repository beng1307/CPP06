#include "ScalarConverter.hpp"
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;

	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;

	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

bool	is_char(std::string &literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (true);
	else
		return (false);
}

bool	is_int(std::string &literal)
{
	size_t	start = 0;

	if (literal[0] == '-' || literal[0] == '+')
		start = 1;	
	for (size_t i = start; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

bool	is_double(std::string &literal)
{
	bool	dot_found = false;
	size_t	start = 0;

	if (literal[0] == '-' || literal[0] == '+')
		start = 1;
	for (size_t i = start; i < literal.length(); i++)
	{
		if ((!(std::isdigit(literal[i]) || literal[i] == '.')))
			return (false);
		if (literal[i] == '.')
		{
			if (dot_found)
				return (false);
			dot_found = true;
		}

	}
	return (true);
}

bool	is_float(std::string &literal)
{
	bool	dot_found = false;
	size_t	start = 0;

	if (literal[literal.length() - 1] != 'f')
		return (false);
	if (literal[0] == '-' || literal[0] == '+')
		start = 1;
	for (size_t i = start; i < literal.length() - 1; i++)
	{
		if ((!(std::isdigit(literal[i]) || literal[i] == '.')))
			return (false);
		if (literal[i] == '.')
		{
			if (dot_found)
				return (false);
			dot_found = true;
		}
	}
	return (true);
}

int	convert_it(std::string &literal)
{
	double	number = 0.0;
	char	*end = NULL;

	if (literal == "nan" || literal == "nanf"
		|| literal == "+inf" || literal == "-inf"
		|| literal == "+inff" || literal == "-inff")
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;

		if (literal[0] == '-')
		{
			std::cout << "Double: -inf" << std::endl;
			std::cout << "Float: -inff" << std::endl;
		}
		else if (literal[0] == '+')
		{
			std::cout << "Double: +inf" << std::endl;
			std::cout << "Float: +inff" << std::endl;
		}
		else
		{
			std::cout << "Double: nan" << std::endl;
			std::cout << "Float: nanf" << std::endl;
		}
		return (OK);
	}

	if (!is_char(literal) && !is_int(literal)
		&& !is_double(literal) && !is_float(literal))
		return (ERROR);

    if (is_char(literal))
		number = static_cast<double>(literal[0]);
	else
		number = std::strtod(literal.c_str(), &end);

	if (std::isnan(number) || std::isinf(number))
		std::cout << "Char: impossible" << std::endl;
	else
	{
		if (!std::isprint(static_cast<char>(number)))
			std::cout << "Char: Non displayable" << std::endl;
		else
			std::cout << "Char: '" << static_cast<char>(number) << "'" << std::endl;
	}
	if (std::isnan(number) || std::isinf(number)
		|| number > static_cast<double>(std::numeric_limits<int>::max())
		|| number < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(number) << std::endl;

	std::cout << "Double: " << std::fixed << std::setprecision(1) << number << std::endl;

	std::cout << "Float: " << std::fixed << std::setprecision(1) << number << "f" << std::endl;

	return (OK);
}

void	ScalarConverter::convert(std::string literal)
{
	if (literal.empty())
	{
		std::cout << "Empty input" << std::endl;
		return ;
	}
	if (convert_it(literal) == ERROR)
		std::cout << "Literal can't be converted." << std::endl;
}
