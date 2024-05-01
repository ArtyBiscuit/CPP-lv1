#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm{
    private:
        std::string _target;
        ShrubberyCreationForm();
    public:
        virtual void execute(Bureaucrat const &executor) const;
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(const ShrubberyCreationForm &form);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
};
#endif