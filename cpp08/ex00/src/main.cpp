#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void){
    try
    {
        std::vector<int> myVec;

        myVec.push_back(25);
        myVec.push_back(67);
        myVec.push_back(38);
        myVec.push_back(42);

        std::cout << *easyfind(myVec, 67) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}