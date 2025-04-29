#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

ScalarConverter::~ScalarConverter() {}

int detect_type(const std::string &literal){
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return CHAR;
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
			literal == "-inf"  || literal == "+inf"  || literal == "nan")
		return SPECIAL;
	else if (literal.find('.') != std::string::npos && literal[literal.length() - 1] == 'f')
		return FLOAT;
	else if (literal.find('.') != std::string::npos)
		return DOUBLE;
	else {
		size_t i = 0;
		if (literal[i] == '+' || literal[i] == '-')
			i++;
		for (; i < literal.length(); ++i) {
			if (!std::isdigit(literal[i]))
				return INVALID;
		}
		return INT;
	}
	return INVALID;
}

void ScalarConverter::convert(const std::string& literal) {
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;

	int type = detect_type(literal);

	switch (type) {
		case CHAR:
			c = literal[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case INT:
			i = std::atoi(literal.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case FLOAT:
			f = static_cast<float>(std::atof(literal.c_str()));
			i = static_cast<int>(f);
			c = static_cast<char>(i);
			d = static_cast<double>(f);
			break;
		case DOUBLE:
			d = std::atof(literal.c_str());
			i = static_cast<int>(d);
			c = static_cast<char>(i);
			f = static_cast<float>(d);
			break;
		case SPECIAL:
			if (literal == "-inff" || literal == "+inff" || literal == "nanf")
				f = static_cast<float>(std::atof(literal.c_str()));
			else
				d = std::atof(literal.c_str());
			break;
		default:
			std::cout << "Invalid literal" << std::endl;
			return;
	}

	// char
	std::cout << "char: ";
	if (type == SPECIAL || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	// int
	std::cout << "int: ";
	if (type == SPECIAL || d < INT_MIN || d > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;

	// float
	std::cout << "float: ";
	if (type == SPECIAL && (literal == "nan" || literal == "nanf"))
		std::cout << "nanf" << std::endl;
	else if (type == SPECIAL && (literal == "+inf" || literal == "+inff"))
		std::cout << "+inff" << std::endl;
	else if (type == SPECIAL && (literal == "-inf" || literal == "-inff"))
		std::cout << "-inff" << std::endl;
	else
		std::cout << f << (f == static_cast<int>(f) ? ".0f" : "f") << std::endl;

	// double
	std::cout << "double: ";
	if (type == SPECIAL && (literal == "nan" || literal == "nanf"))
		std::cout << "nan" << std::endl;
	else if (type == SPECIAL && (literal == "+inf" || literal == "+inff"))
		std::cout << "+inf" << std::endl;
	else if (type == SPECIAL && (literal == "-inf" || literal == "-inff"))
		std::cout << "-inf" << std::endl;
	else
		std::cout << d << (d == static_cast<int>(d) ? ".0" : "") << std::endl;
}
