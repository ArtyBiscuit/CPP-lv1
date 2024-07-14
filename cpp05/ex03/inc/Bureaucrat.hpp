#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"

class	AForm;

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
        void                signForm(AForm &f);
        void                executeForm(AForm const &form);

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
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat(const std::string name, unsigned int grade);
        ~Bureaucrat();
};

std::ostream    &operator<<(std::ostream &output, Bureaucrat const &Bureaucrat);

#endif