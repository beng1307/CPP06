#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include	<string>

#define		OK 0
#define		ERROR 1

class	ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &other);
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

	public:

		static void	convert(std::string literal);
};


#endif