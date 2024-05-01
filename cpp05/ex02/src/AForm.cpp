#include "AForm.hpp"

// AForm    &AForm::operator=(const AForm &src){
//     *this = src;
//     return (*this);
// }

AForm    &AForm::operator=(const AForm &src){
    this->_signed = src._signed;
    return (*this);
}

// Print all AForm info.
std::ostream    &operator<<(std::ostream &output, AForm const &f){
    output << f.getName();
    output << ", Form grade ";
    output << f.getGradeToSign();
    output << ", Grade for execution ";
    output << f.getGradeToExecute();
    output << ", Signed ";
    output << f.getSigned();
    output << ".";
    return (output);
}

AForm::AForm(std::string name, unsigned int grade_to_sign, unsigned int grade_to_execute) :  _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute){
    this->_signed = false;
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
    else if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
}

AForm::AForm() : _name("none"), _grade_to_sign(0), _grade_to_execute(0){
}

AForm::~AForm(){

}

std::string AForm::getName() const{
    return (this->_name);
}

bool     AForm::getSigned() const{
    return (this->_signed);
}

unsigned int     AForm::getGradeToSign() const{
    return (this->_grade_to_sign);
}

unsigned int     AForm::getGradeToExecute() const{
    return (this->_grade_to_execute);
}

void     AForm::beSigned(Bureaucrat &Bur){
    if(Bur.getGrade() > this->_grade_to_sign){
        throw GradeTooLowException();
    }
    this->_signed = true;
}

const char* AForm::GradeTooHighException::what(void) const throw() {
    return ("AForm: Grade too high Exception!");
}

const char* AForm::GradeTooLowException::what(void) const throw() {
    return ("AForm: Grade too Low Exception!");
}

const char* AForm::IsNotSigned::what(void) const throw() {
    return ("Form: is not signed!");
}