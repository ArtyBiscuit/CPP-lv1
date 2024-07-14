#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const unsigned int _grade_to_sign;
        const unsigned int _grade_to_execute;
        AForm();
    public:
        std::string     getName() const;
        bool            getSigned() const;
        unsigned int    getGradeToSign() const;
        unsigned int    getGradeToExecute() const;

        void    beSigned(Bureaucrat &Bur);
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class IsNotSigned : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        AForm &operator=(const AForm &src);
        AForm(const AForm &src);
        AForm(std::string name, unsigned int grade_to_sign, unsigned int grade_to_execute);
        virtual ~AForm();
};

std::ostream    &operator<<(std::ostream &output, AForm const &f);

#endif