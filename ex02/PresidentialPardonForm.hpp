#ifndef PRESIODENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
            std::string _target;

            PresidentialPardonForm();
    public:
            PresidentialPardonForm(const std::string& target);
            PresidentialPardonForm(const PresidentialPardonForm& src);
            PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
            ~PresidentialPardonForm();

            void execute(Bureaucrat const & executor) const;
};

#endif