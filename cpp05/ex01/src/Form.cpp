#include "Form.hpp"

Form&	Form::operator=(const Form &src) {
	if (this != &src) {
		this->_signed = src._signed;
	}
	return (*this);
}


// Print all Form info.
std::ostream    &operator<<(std::ostream &output, Form const &f){
    output << f.getName();
    output << ", Form grade ";
    output << f.getGradeToSign();
    output << ".";
    return (output);
}

Form::Form(std::string name, unsigned int grade_to_sign, unsigned int grade_to_execute) :  _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute){
    this->_signed = false;
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
    else if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
}

Form::Form(const Form &src): _name(src._name), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute()) {
	*this = src;
}

Form::Form() : _name("none"), _grade_to_sign(0), _grade_to_execute(0){
}

Form::~Form(){

}

std::string Form::getName() const{
    return (this->_name);
}

bool     Form::getSigned(){
    return (this->_signed);
}

unsigned int     Form::getGradeToSign() const{
    return (this->_grade_to_sign);
}

unsigned int     Form::getGradeToExecute() const{
    return (this->_grade_to_execute);
}

void     Form::beSigned(Bureaucrat &Bur){
    if(Bur.getGrade() < this->_grade_to_sign){
        throw GradeTooLowException();
    }
    this->_signed = true;
}

const char* Form::GradeTooHighException::what(void) const throw() {
    return ("Form: Grade too high Exception!");
}

const char* Form::GradeTooLowException::what(void) const throw() {
    return ("Form: Grade too Low Exception!");
}