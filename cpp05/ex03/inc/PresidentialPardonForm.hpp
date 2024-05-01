#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm{
    private:
        std::string _target;
        PresidentialPardonForm();
    public:
        virtual void execute(Bureaucrat const &executor) const;
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm &form);
        virtual ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
};
#endif