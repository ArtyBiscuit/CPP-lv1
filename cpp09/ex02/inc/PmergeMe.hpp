#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <iostream>
# include <cstdlib>
# include <iomanip>

void printVector(const std::vector<int> &vec, std::string flag);
void printDeque(const std::deque<int> &vec, std::string flag);

std::vector<int> mergeInsertVector(std::vector<int> array);
std::deque<int> mergeInsertDeque(std::deque<int> array);

class BadInput : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("ERROR: Bad input.");
        }; 
};

#endif
