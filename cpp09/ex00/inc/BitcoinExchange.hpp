#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <regex.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cstring>
#include <exception>

class BadLine : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("ERROR: Bad line.");
        }; 
};

class BadFile : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("ERROR: Bad file.");
        }; 
};

class BadHeader : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("ERROR: Bad header file.");
        }; 
};

class BadInput : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("ERROR: Bad user input.");
        }; 
};
#endif