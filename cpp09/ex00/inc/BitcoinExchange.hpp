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
#include <list>

void bitcoinExchange(int argv, char **argc);

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

class invalidDate : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("ERROR: invalid date.");
        }; 
};

class badWallet : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("ERROR: Wallet not acceptable value.");
        }; 
};

#endif