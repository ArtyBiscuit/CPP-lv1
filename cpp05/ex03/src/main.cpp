#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"

void AFormTest();
void BureaucratTest();
void BasicOperation();

int main(void){

    Intern Lolo;
    AForm* RRF;

    RRF = Lolo.makeForm("RobotomyRequest", "Bender");
    Bureaucrat Stev = Bureaucrat("Stev", 72);
    Bureaucrat Moris = Bureaucrat("Moris", 45);
    Stev.signForm(*RRF);
    std::cout << *RRF << std::endl;
    Moris.executeForm(*RRF);

    // try{
    //     Bureaucrat Stev = Bureaucrat("Stev", 145);
    //     Bureaucrat Moris = Bureaucrat("Moris", 114);
    //     ShrubberyCreationForm PPF = ShrubberyCreationForm("Arty");
    //     Stev.signForm(PPF);
    //     std::cout << PPF << std::endl;
    //     Moris.executeForm(PPF);
    // }
    // catch (std::exception &e){
    //     std::cout << e.what() << std::endl;
    // }
    // try{
    //     Bureaucrat Stev = Bureaucrat("Stev", 25);
    //     Bureaucrat Moris = Bureaucrat("Moris", 5);
    //     PresidentialPardonForm PPF = PresidentialPardonForm("Arty");
    //     Stev.signForm(PPF);
    //     std::cout << PPF << std::endl;
    //     Moris.executeForm(PPF);
    // }
    // catch (std::exception &e){
    //     std::cout << e.what() << std::endl;
    // }
    // try{
    //     Bureaucrat Stev = Bureaucrat("Stev", 72);
    //     Bureaucrat Moris = Bureaucrat("Moris", 45);
    //     RobotomyRequestForm PPF = RobotomyRequestForm("Arty");
    //     Stev.signForm(PPF);
    //     std::cout << PPF << std::endl;
    //     Moris.executeForm(PPF);
    // }
    // catch (std::exception &e){
    //     std::cout << e.what() << std::endl;
    // }

    // BasicOperation();
    // AFormTest();
    // BureaucratTest();
    return (0);
}

// void BasicOperation(){
//     std::cout << YELLOW << "Basic Operation." << RESET << std::endl;
//     Bureaucrat Stev = Bureaucrat("Stev", 42);

//     std::string form_name = "A-54";
//     unsigned int grade_to_sign = 42;
//     unsigned int grade_to_execute = 100;
//     AForm myAForm = AForm(form_name, grade_to_sign, grade_to_execute);

//     std::cout << Stev << std::endl;
//     std::cout << myAForm << std::endl;
//     Stev.signAForm(myAForm);
//     std::cout << std::endl;
// }

// void AFormTest(){
//     std::cout << YELLOW << "AForm Test." << RESET << std::endl;
//     try{
//         std::string     form_name = "B-23";
//         unsigned int    grade_to_sign = 0;
//         unsigned int    grade_to_execute = 10;

//         std::string     bureaucrat_name = "Moris";
//         unsigned int    bureaucrat_grade = 10;

//         Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
//         AForm myAForm = AForm(form_name, grade_to_sign, grade_to_execute);

//         std::cout << Stev << std::endl;
//         std::cout << myAForm << std::endl;
//         Stev.signAForm(myAForm);
//     }
//     catch (std::exception &e){
//         std::cout << e.what() << std::endl;
//     }

//         try{
//         std::string     form_name = "B-24";
//         unsigned int    grade_to_sign = 10;
//         unsigned int    grade_to_execute = 10;

//         std::string     bureaucrat_name = "Lary";
//         unsigned int    bureaucrat_grade = 0;

//         Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
//         AForm myAForm = AForm(form_name, grade_to_sign, grade_to_execute);

//         std::cout << Stev << std::endl;
//         std::cout << myAForm << std::endl;
//         Stev.signAForm(myAForm);
//     }
//     catch (std::exception &e){
//         std::cout << e.what() << std::endl;
//     }

//     try{
//         std::string     form_name = "C-32";
//         unsigned int    grade_to_sign = 150;
//         unsigned int    grade_to_execute = 10;

//         std::string     bureaucrat_name = "Bob";
//         unsigned int    bureaucrat_grade = 151;

//         Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
//         AForm myAForm = AForm(form_name, grade_to_sign, grade_to_execute);

//         std::cout << Stev << std::endl;
//         std::cout << myAForm << std::endl;
//         Stev.signAForm(myAForm);
//     }
//     catch (std::exception &e){
//         std::cout << e.what() << std::endl;
//     }

//     try{
//         std::string     form_name = "C-32";
//         unsigned int    grade_to_sign = 151;
//         unsigned int    grade_to_execute = 10;

//         std::string     bureaucrat_name = "Jean";
//         unsigned int    bureaucrat_grade = 150;

//         Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
//         AForm myAForm = AForm(form_name, grade_to_sign, grade_to_execute);

//         std::cout << Stev << std::endl;
//         std::cout << myAForm << std::endl;
//         Stev.signAForm(myAForm);
//     }
//     catch (std::exception &e){
//         std::cout << e.what() << std::endl;
//     }

//     try{
//         std::string     form_name = "G-72";
//         unsigned int    grade_to_sign = 15;
//         unsigned int    grade_to_execute = 10;

//         std::string     bureaucrat_name = "Patrick";
//         unsigned int    bureaucrat_grade = 16;

//         Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
//         AForm myAForm = AForm(form_name, grade_to_sign, grade_to_execute);

//         std::cout << Stev << std::endl;
//         std::cout << myAForm << std::endl;
//         Stev.signAForm(myAForm);
//     }
//     catch (std::exception &e){
//         std::cout << e.what() << std::endl;
//     }

//     try{
//         std::string     form_name = "F-69";
//         unsigned int    grade_to_sign = -1;
//         unsigned int    grade_to_execute = 10;

//         std::string     bureaucrat_name = "Philippe";
//         unsigned int    bureaucrat_grade = 15;

//         Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
//         AForm myAForm = AForm(form_name, grade_to_sign, grade_to_execute);

//         std::cout << Stev << std::endl;
//         std::cout << myAForm << std::endl;
//         Stev.signAForm(myAForm);
//     }
//     catch (std::exception &e){
//         std::cout << e.what() << std::endl;
//     }
//     std::cout << std::endl;
// }