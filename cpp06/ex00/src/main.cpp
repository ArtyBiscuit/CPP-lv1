#include "ScalarConverter.hpp"

bool UserInput(int argv){
    if(argv < 2 || argv > 2){
        std::cout << "Bad user input." << std::endl;
        return (false);
    }
    return (true);
}

int main(int argv, char **argc){
    if(UserInput(argv))
        ScalarConverter::convert(argc[1]);
    return (0);
}