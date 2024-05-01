#include "AForm.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"



Intern    &Intern::operator=(const Intern &src){
    return (*this);
}

AForm *makePresidentialPardonForm(std::string name){
    return (new PresidentialPardonForm(name));
}

AForm *makeRobotomyRequestForm(std::string name){
    return (new RobotomyRequestForm(name));
}

AForm *makeShrubberyCreationForm(std::string name){
    return (new ShrubberyCreationForm(name));
}

AForm* Intern::makeForm(std::string name, std::string target) {

    

    std::string nameOfForm[] = {
        "PresidentialPardon",
        "RobotomyRequest",
        "ShrubberyCreation"
    };

    AForm *(*fun_ptr[])(std::string) = {
        makePresidentialPardonForm,
        makeRobotomyRequestForm,
        makeShrubberyCreationForm
    };

    for(int i = 0; i < 3; i++){
        if(nameOfForm[i] == name){
            return (fun_ptr[i](target));
        }
    }
    
    throw NameDoesNotExist();
    return 0;
}

const char* Intern::NameDoesNotExist::what(void) const throw() {
    return ("Intern: The name of this Form does not exist.");
}

Intern::Intern(){
}

Intern::~Intern(){
} 