#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <float.h>
# include <iostream>
# include <stdlib.h>
# include <limits.h>


# define INT_TYPE 0
# define CHAR_TYPE 1
# define FLOAT_TYPE 2
# define DOOBLE_TYPE 3

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
		ScalarConverter&	operator=(const ScalarConverter &src);
    public:
        static void convert(std::string str);
        ~ScalarConverter();

};

#endif
