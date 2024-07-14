#include "PresidentialPardonForm.hpp"

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form), _target(form._target){
    *this = form;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if(!AForm::getSigned()){
        throw IsNotSigned();
    }
    else if(executor.getGrade() > AForm::getGradeToExecute()){
        throw GradeTooLowException();
    }
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5), _target(target){
};

PresidentialPardonForm::PresidentialPardonForm() : AForm("none", 0, 0), _target("none"){
};

PresidentialPardonForm::~PresidentialPardonForm(){
};