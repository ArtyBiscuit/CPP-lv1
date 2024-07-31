#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <regex.h>
#include <string>
#include <sstream>

void start(int argv, char **argc);

class Error : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("ERROR: Bad input.");
        }; 
};

class divisByZero : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("ERROR: Division by zero.");
        }; 
};

#endif