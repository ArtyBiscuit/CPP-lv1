#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Form.hpp"

class	Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        unsigned int        _grade;
        Bureaucrat();
    public:
        std::string   getName() const;
        unsigned int        getGrade() const;
        void                increaseGrade();
        void                decreaseGrade();
        void                signForm(Form &f);

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

        Bureaucrat &operator=(const Bureaucrat &src);
        Bureaucrat(const std::string name, unsigned int grade);
        ~Bureaucrat();
};

std::ostream    &operator<<(std::ostream &output, Bureaucrat const &Bureaucrat);

#endif