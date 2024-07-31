#include "RPN.hpp"

int main(int argv, char **argc) {
    try
    {
        start(argv, argc);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

