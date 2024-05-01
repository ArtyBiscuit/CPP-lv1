#include "Bureaucrat.hpp"

int main(void){
    Bureaucrat Stev = Bureaucrat("Stev", 42);
    std::cout << Stev << std::endl;

    try{
        Bureaucrat Moris = Bureaucrat("Moris", 255);
        std::cout << Moris << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat Lary = Bureaucrat("Lary", 0);
        std::cout << Lary << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat Bob = Bureaucrat("Bob", 150);
        std::cout << Bob << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat Jean = Bureaucrat("Jean", -1);
        std::cout << Jean << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat Patrick = Bureaucrat("Patrick", 151);
        std::cout << Patrick << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        Bureaucrat Philippe = Bureaucrat("Philippe", 1);
        std::cout << Philippe << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}