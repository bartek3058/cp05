#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
            const std::string   _name;
            bool                _isSigned;
            const int           _gradeToSign;
            const int           _gradeToExecute;

    public:
            AForm();
            AForm(const std::string& name, int gradeToSign, int gradeToExecute);
            AForm(const AForm& src);
            AForm& operator=(const AForm& src);
            ~AForm();
        
            const std::string& getName() const;
            bool getIsSigned() const;
            const int getGradeToSign() const;
            const int getGradeToExecute() const;

            void beSigned(const Bureaucrat& bureaucrat);

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

            class FormNotSignedException : public std::exception
            {
                public:
                        virtual const char* what() const throw();
            };

            virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif