#include "Bureaucrat.hpp"

Bureaucrat    &Bureaucrat::operator=(const Bureaucrat &src){
    *this = src;
    return (*this);
}

std::ostream    &operator<<(std::ostream &output, Bureaucrat const &br){
    output << br.getName();
    output << ", bureaucrat grade ";
    output << br.getGrade();
    output << ".";
    return (output);
}

Bureaucrat::Bureaucrat(){
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const{
    return (this->_name);
}

unsigned int Bureaucrat::getGrade() const{
    return (this->_grade);
}

void Bureaucrat::increaseGrade(){
    if((this->_grade - 1) >= 1)
        throw GradeTooHighException();
    else
        this->_grade -= 1;
}
void Bureaucrat::decreaseGrade(){
    if((this->_grade + 1) <= 150)
        throw GradeTooLowException();
    else
        this->_grade += 1;
}

void Bureaucrat::signForm(AForm &f){
    try{
        f.beSigned(*this);
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e){
        std::cout << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form){
    try{
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
        form.execute(*this);
    }
    catch (std::exception &e){
        std::cout << this->getName() << " could not execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
    return ("Bureaucrat: Grade too high Exception!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
    return ("Bureaucrat: Grade too Low Exception!");
}