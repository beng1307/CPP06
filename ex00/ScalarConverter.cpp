#include "ScalarConverter.hpp"
#include <string>

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


bool	is_int(std::string &literal)
{
	int	start = 0;

	if (literal[0] == '-' || literal[0] == '+')
		start = 1;	
	for (int i = start; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

bool	is_float(std::string &literal)
{
	bool	dot_found = false;
	int		start = 0;

	if (literal.back() != 'f')
		return (false);
	if (literal[0] == '-' || literal[0] == '+')
		start = 1;
	for (int i = start; i < literal.length() - 1; i++)
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

bool	is_double(std::string &literal)
{
	bool	dot_found = false;
	int		start = 0;

	if (literal[0] == '-' || literal[0] == '+')
		start = 1;
	for (int i = start; i < literal.length(); i++)
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

void	convert_it(std::string &literal)
{
	if (is_char(literal))
		convert_from_char();
	else if (is_int(literal))
		convert_from_number();
	else if (is_double(literal))
		return (DOUBLE);
	else if (is_float(literal))
		return (FLOAT);
	else
		return (ERROR);
}

bool	is_char(std::string &literal)
{
	if (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\''
		&& std::isprint(literal[1]))
		return (true);
}

void	ScalarConverter::convert(std::string literal)
{

	convert_it()
	else
		std::cout << "Literal can't be converted" << std::endl;
}