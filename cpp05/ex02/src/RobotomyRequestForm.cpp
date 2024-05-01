#include "RobotomyRequestForm.hpp"

RobotomyRequestForm    &RobotomyRequestForm::operator=(const RobotomyRequestForm &src){
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form), _target(form._target){
    *this = form;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    if(!AForm::getSigned()){
        throw IsNotSigned();
    }
    else if(executor.getGrade() > AForm::getGradeToExecute()){
        throw GradeTooLowException();
    }

    std::cout << "VVVVVVVVVVVVVVVVVVV!!!" << std::endl;
    std::cout << "VRRRRRRRRRRRRR!!!" << std::endl;
    std::cout << "....." << std::endl;
    std::cout << "VWRRRRRRRR!!!" << std::endl;

    char random_bit;
    std::fstream fs;
    fs.open("/dev/urandom", std::ios::in | std::ios::binary);
    fs.read(&random_bit, sizeof(char));
    if(random_bit % 2 == 0)
        std::cout << this->_target << " has been robotomized successfull !" << std::endl;
    else
        std::cout << "the robotomy has failed." << std::endl;
    fs.close();
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45), _target(target){
};

RobotomyRequestForm::RobotomyRequestForm() : AForm("none", 0, 0), _target("none"){
};

RobotomyRequestForm::~RobotomyRequestForm(){
};