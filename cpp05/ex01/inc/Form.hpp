#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const unsigned int _grade_to_sign;
        const unsigned int _grade_to_execute;
        Form();
    public:
        std::string     getName() const;
        bool            getSigned();
        unsigned int    getGradeToSign() const;
        unsigned int    getGradeToExecute() const;

        void    beSigned(Bureaucrat &Bur);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        Form &operator=(const Form &src);
        Form(std::string name, unsigned int grade_to_sign, unsigned int grade_to_execute);
        ~Form();
};

std::ostream    &operator<<(std::ostream &output, Form const &f);

#endif