#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm    &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src){
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form), _target(form._target){
    *this = form;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    if(!AForm::getSigned()){
        throw IsNotSigned();
    }
    else if(executor.getGrade() > AForm::getGradeToExecute()){
        throw GradeTooLowException();
    }

    std::string file_name = this->_target + "_shrubbery";
    std::ofstream fichier(file_name.c_str());
    fichier << "          &&& &&  & &&\n";
    fichier << "      && &\\/&\\|& ()|/ @, &&\n";
    fichier << "      &\\/(/&/&||/& /_/)_&/_&\n";
    fichier << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
    fichier << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
    fichier << "&&   && & &| &| /& & % ()& /&&\n";
    fichier << " ()&_---()&\\&\\|&&-&&--%---()~\n";
    fichier << "     &&     \\|||\n";
    fichier << "             |||\n";
    fichier << "             |||\n";
    fichier << "             |||\n";
    fichier << "       , -=-~  .-^- _\n\n";
    fichier << "          &&& &&  & &&\n";
    fichier << "      && &\\/&\\|& ()|/ @, &&\n";
    fichier << "      &\\/(/&/&||/& /_/)_&/_&\n";
    fichier << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
    fichier << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
    fichier << "&&   && & &| &| /& & % ()& /&&\n";
    fichier << " ()&_---()&\\&\\|&&-&&--%---()~\n";
    fichier << "     &&     \\|||\n";
    fichier << "             |||\n";
    fichier << "             |||\n";
    fichier << "             |||\n";
    fichier << "       , -=-~  .-^- _\n";
    fichier.close();
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target){
};

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("none", 0, 0), _target("none"){
};

ShrubberyCreationForm::~ShrubberyCreationForm(){
};