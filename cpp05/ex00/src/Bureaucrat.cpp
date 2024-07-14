#include "Bureaucrat.hpp"


Bureaucrat& Bureaucrat::operator=(Bureaucrat const &src) {
    if (this != &src) {
        this->_grade = src.getGrade();
    }
    return (*this);
}

std::ostream    &operator<<(std::ostream &output, Bureaucrat const &br){
    output << br.getName();
    output << ", bureaucrat grade ";
    output << br.getGrade();
    output << ".";
    return (output);
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name) {
    *this = src;
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
    if((this->_grade - 1) < 1)
        throw GradeTooHighException();
    else
        this->_grade -= 1;
}
void Bureaucrat::decreaseGrade(){
    if((this->_grade + 1) > 150)
        throw GradeTooLowException();
    else
        this->_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
    return ("Grade too high Exception!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
    return ("Grade too Low Exception!");
}