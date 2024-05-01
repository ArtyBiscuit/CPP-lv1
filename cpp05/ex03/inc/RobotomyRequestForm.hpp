#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;
        RobotomyRequestForm();
    public:
        virtual void execute(Bureaucrat const &executor) const;
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm &form);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
};
#endif