#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
            const std::string   _name;
            bool                _isSigned;
            const int           _gradeToSign;
            const int           _gradeToExecute;

    public:
            Form();
            Form(const std::string& name, int gradeToSign, int gradeToExecute);
            Form(const Form& src);
            Form& operator=(const Form& src);
            ~Form();
        
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
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif