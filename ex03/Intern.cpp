#include "Intern.hpp"


Intern::Intern(){}

Intern::Intern(const Intern& src){(void)src;}

Intern& Intern::operator=(const Intern& src){(void)src; return *this;}

Intern::~Intern(){}

static AForm* makeShrubbery(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm* makePresidential(const std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    struct FormType
    {
        std::string name;
        AForm* (*func)(const std::string);
    };

    FormType forms[] =
    {
        {"shrubbery creation", &makeShrubbery},
        {"robotomy request", &makeRobotomy},
        {"presidential pardon", &makePresidential}
    };

    for (int i = 0; i < 3; i++)
    {
        if (forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].func(target);
        }
    }
    std::cout << "Intern cannot create " << formName << " because it doesn't exist." << std::endl;
    return NULL;
}