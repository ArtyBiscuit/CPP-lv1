#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"

void FormTest();
void BureaucratTest();
void BasicOperation();

int main(void){
    BasicOperation();
    FormTest();
    BureaucratTest();
    return (0);
}

void BasicOperation(){
    std::cout << YELLOW << "Basic Operation." << RESET << std::endl;
    Bureaucrat Stev = Bureaucrat("Stev", 42);

    std::string form_name = "A-54";
    unsigned int grade_to_sign = 42;
    unsigned int grade_to_execute = 100;
    Form myForm = Form(form_name, grade_to_sign, grade_to_execute);

    std::cout << Stev << std::endl;
    std::cout << myForm << std::endl;
    Stev.signForm(myForm);
    std::cout << std::endl;
}

void FormTest(){
    std::cout << YELLOW << "Form Test." << RESET << std::endl;
    try{
        std::string     form_name = "B-23";
        unsigned int    grade_to_sign = 0;
        unsigned int    grade_to_execute = 10;

        std::string     bureaucrat_name = "Moris";
        unsigned int    bureaucrat_grade = 10;

        Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
        Form myForm = Form(form_name, grade_to_sign, grade_to_execute);

        std::cout << Stev << std::endl;
        std::cout << myForm << std::endl;
        Stev.signForm(myForm);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

        try{
        std::string     form_name = "B-24";
        unsigned int    grade_to_sign = 10;
        unsigned int    grade_to_execute = 10;

        std::string     bureaucrat_name = "Lary";
        unsigned int    bureaucrat_grade = 0;

        Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
        Form myForm = Form(form_name, grade_to_sign, grade_to_execute);

        std::cout << Stev << std::endl;
        std::cout << myForm << std::endl;
        Stev.signForm(myForm);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        std::string     form_name = "C-32";
        unsigned int    grade_to_sign = 150;
        unsigned int    grade_to_execute = 10;

        std::string     bureaucrat_name = "Bob";
        unsigned int    bureaucrat_grade = 151;

        Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
        Form myForm = Form(form_name, grade_to_sign, grade_to_execute);

        std::cout << Stev << std::endl;
        std::cout << myForm << std::endl;
        Stev.signForm(myForm);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        std::string     form_name = "C-32";
        unsigned int    grade_to_sign = 151;
        unsigned int    grade_to_execute = 10;

        std::string     bureaucrat_name = "Jean";
        unsigned int    bureaucrat_grade = 150;

        Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
        Form myForm = Form(form_name, grade_to_sign, grade_to_execute);

        std::cout << Stev << std::endl;
        std::cout << myForm << std::endl;
        Stev.signForm(myForm);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        std::string     form_name = "G-72";
        unsigned int    grade_to_sign = 15;
        unsigned int    grade_to_execute = 10;

        std::string     bureaucrat_name = "Patrick";
        unsigned int    bureaucrat_grade = 16;

        Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
        Form myForm = Form(form_name, grade_to_sign, grade_to_execute);

        std::cout << Stev << std::endl;
        std::cout << myForm << std::endl;
        Stev.signForm(myForm);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        std::string     form_name = "F-69";
        unsigned int    grade_to_sign = -1;
        unsigned int    grade_to_execute = 10;

        std::string     bureaucrat_name = "Philippe";
        unsigned int    bureaucrat_grade = 15;

        Bureaucrat Stev = Bureaucrat(bureaucrat_name, bureaucrat_grade);
        Form myForm = Form(form_name, grade_to_sign, grade_to_execute);

        std::cout << Stev << std::endl;
        std::cout << myForm << std::endl;
        Stev.signForm(myForm);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void BureaucratTest(){
    std::cout << YELLOW << "Bureaucrat Test." << RESET << std::endl;
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
    std::cout << std::endl;
}