#include "BitcoinExchange.hpp"

int main(int argv, char **argc) {
    try
    {
        bitcoinExchange(argv, argc);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}