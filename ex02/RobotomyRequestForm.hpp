#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
            std::string _target;

            RobotomyRequestForm();
    public:
            RobotomyRequestForm(const std::string& target);
            RobotomyRequestForm(const RobotomyRequestForm& src);
            RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
            ~RobotomyRequestForm();

            void execute(Bureaucrat const & executor) const;
};

#endif