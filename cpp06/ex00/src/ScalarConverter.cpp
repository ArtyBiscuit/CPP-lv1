#include "ScalarConverter.hpp"

#include <iomanip> //find_first_not_of

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
        std::cout << (int)i << std::endl;
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

void DisplayExeption(std::string str){
    if(str == "+inff" || str == "+inf"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "inff" << std::endl;
        std::cout << "dooble: " << "inf" << std::endl;
    }
    if(str == "-inff" || str == "-inf"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "-inff" << std::endl;
        std::cout << "dooble: " << "-inf" << std::endl;
    }
    if(str == "nan"){
        // a finir.
    }
    else{
        std::cout << "Unsupported argument." << std::endl;
    }
}

char getChar(std::string str){
    return (str[1]);
}

void ScalarConverter::convert(std::string str){
    switch (CheckType(str))
    {
        case CHAR_TYPE:
            // std::cout << "Char Type" << std::endl << std::endl;
            DisplayChar((int)getChar(str));
            DisplayInt((long int)getChar(str));
            DisplayFloat((float)getChar(str));
            DisplayDouble((double)getChar(str));
        break;
        case FLOAT_TYPE:
            // std::cout << "Float Type" << std::endl << std::endl;
            DisplayChar((int)atof(str.c_str()));
            DisplayInt((long int)atof(str.c_str()));
            DisplayFloat((float)atof(str.c_str()));
            DisplayDouble(atof(str.c_str()));
        break;
        case DOOBLE_TYPE:
            // std::cout << "Dooble Type" << std::endl << std::endl;
            DisplayChar((int)atof(str.c_str()));
            DisplayInt((long int)atof(str.c_str()));
            DisplayFloat((float)atof(str.c_str()));
            DisplayDouble(atof(str.c_str()));
        break;
        case INT_TYPE:
            // std::cout << "Int Type" << std::endl << std::endl;
            DisplayChar((int)atof(str.c_str()));
            DisplayInt((long int)atof(str.c_str()));
            DisplayFloat((float)atof(str.c_str()));
            DisplayDouble(atof(str.c_str()));
        break;
        default:
            DisplayExeption(str);
        break;
    }


}

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}