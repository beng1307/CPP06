#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include	<string>

#define		CHAR 1
#define		INT 2
#define		DOUBLE 3
#define		FLOAT 4
#define		ERROR 5

class	ScalarConverter
{
	private:

		int		type;
		int		int_literal;
		float	float_literal;
		double	double_literal;
		char	char_literal;

		ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &other);
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

	public:

		static void	convert(std::string literal);
};


#endif