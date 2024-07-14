#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){

    Intern Lolo;
    AForm* RRF;

    RRF = Lolo.makeForm("RobotomyRequest", "Bender");
    Bureaucrat Stev = Bureaucrat("Stev", 72);
    Bureaucrat Moris = Bureaucrat("Moris", 45);
    Stev.signForm(*RRF);
    std::cout << *RRF << std::endl;
    Moris.executeForm(*RRF);

    try{
        Bureaucrat Stev = Bureaucrat("Stev", 145);
        Bureaucrat Moris = Bureaucrat("Moris", 114);
        ShrubberyCreationForm PPF = ShrubberyCreationForm("Arty");
        Stev.signForm(PPF);
        std::cout << PPF << std::endl;
        Moris.executeForm(PPF);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        Bureaucrat Stev = Bureaucrat("Stev", 25);
        Bureaucrat Moris = Bureaucrat("Moris", 5);
        PresidentialPardonForm PPF = PresidentialPardonForm("Arty");
        Stev.signForm(PPF);
        std::cout << PPF << std::endl;
        Moris.executeForm(PPF);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        Bureaucrat Stev = Bureaucrat("Stev", 72);
        Bureaucrat Moris = Bureaucrat("Moris", 45);
        RobotomyRequestForm PPF = RobotomyRequestForm("Arty");
        Stev.signForm(PPF);
        std::cout << PPF << std::endl;
        Moris.executeForm(PPF);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return (0);
}