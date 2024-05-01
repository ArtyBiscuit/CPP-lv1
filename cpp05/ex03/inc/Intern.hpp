#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"

class Intern{
    private:
    public:
        AForm *makeForm(std::string name, std::string target);
        
        class NameDoesNotExist : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        Intern();
        ~Intern();
        Intern &operator=(const Intern &src);
};

#endif