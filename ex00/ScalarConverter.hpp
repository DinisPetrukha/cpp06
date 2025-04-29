#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <string>
#include <limits.h>
#include <float.h>

enum	e_type
{
	SPECIAL = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INVALID = -1
};

class ScalarConverter {
	private:
		ScalarConverter(); // não instanciável
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();
	public:
		static void convert(const std::string & literal);
};

int	detect_type(const std::string &literal);

#endif