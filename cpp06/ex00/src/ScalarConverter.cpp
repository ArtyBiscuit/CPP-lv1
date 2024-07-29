#include "ScalarConverter.hpp"

#include <iomanip>

void DisplayChar(int c){
    std::cout << "char: ";
    if(c >= 32 && c <= 126)
        std::cout << "'" << (char)c << "'" << std::endl;
    else if((c >= 0 && c <= 31) || (c == 127))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;

}

void DisplayFloat(double f){
    std::cout << "float: ";
    if((f >= -FLT_MAX && f <= FLT_MAX))
        std::cout << std::fixed << std::setprecision(6) << f << "f" << std::endl;
    else
        std::cout << "nanf" << std::endl;
}

void DisplayDouble(long double d){
    std::cout << "double: ";
    if(d >= -DBL_MAX && d <= DBL_MAX)
        std::cout << d << std::endl;
    else
        std::cout << "nan" << std::endl;
}

void DisplayInt(long int i){
    std::cout << "int: ";
    if(i >= INT_MIN && i <= INT_MAX)
        std::cout << static_cast<int>(i) << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

bool    IsNum(const std::string &literal)
{
    int    i = 0;
    if (literal.length() == 1 && literal[0] == 'f')
        return (false);
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    while (literal[i] && std::isdigit(literal[i]))
        i++;
    if (literal[i] == '.' && i)
        i++;
    while (literal[i] && std::isdigit(literal[i]))
        i++;
    if (literal[i] == 'f')
        i++;
    return ((size_t) i == literal.length() && i);
}

int CheckType(std::string str){
    if(str.size() == 3 && str[0] == '\'' && str[2] == '\'')
        return (CHAR_TYPE);
    else if(str.find_first_not_of("-0123456789") == std::string::npos && IsNum(str))
        return (INT_TYPE);
    else if(str.find_first_not_of("-.0123456789") == std::string::npos && IsNum(str))
        return (DOOBLE_TYPE);
    else if(str.find_first_not_of("-.f0123456789") == std::string::npos && IsNum(str))
        return (FLOAT_TYPE);
    return (-1);
}

void DisplayExeption(std::string str)
{
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "dooble: " << str << std::endl;
	}
	else if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
		// c'est magic
		str[3] = 0;
        std::cout << "dooble: " << str << std::endl;
	}
    else{
        std::cout << "Unsupported argument." << std::endl;
    }
}

void ScalarConverter::convert(std::string str){
    switch (CheckType(str))
    {
        case CHAR_TYPE:
            DisplayChar(static_cast<int>(str[1]));
            DisplayInt(static_cast<long int>(str[1]));
            DisplayFloat(static_cast<float>(str[1]));
            DisplayDouble(static_cast<double>(str[1]));
        break;
        case FLOAT_TYPE:
            DisplayChar(static_cast<int>(atof(str.c_str())));
            DisplayInt(static_cast<long int>(atof(str.c_str())));
            DisplayFloat(static_cast<float>(atof(str.c_str())));
            DisplayDouble(static_cast<double>(atof(str.c_str())));
        break;
        case DOOBLE_TYPE:
            DisplayChar(static_cast<int>(atof(str.c_str())));
            DisplayInt(static_cast<long int>(atof(str.c_str())));
            DisplayFloat(static_cast<float>(atof(str.c_str())));
            DisplayDouble(static_cast<double>(atof(str.c_str())));
        break;
        case INT_TYPE:
            DisplayChar(static_cast<int>(atof(str.c_str())));
            DisplayInt(static_cast<long int>(atof(str.c_str())));
            DisplayFloat(static_cast<float>(atof(str.c_str())));
            DisplayDouble(static_cast<double>(atof(str.c_str())));
        break;
        default:
            DisplayExeption(str);
        break;
    }
}

ScalarConverter    &ScalarConverter::operator=(const ScalarConverter &src){
    (void)src;
    return (*this);
}

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}
