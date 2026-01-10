#include "Form.hpp"

Form::Form(): _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){}

Form::Form(const std::string& name, int gradeToSing, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSing), _gradeToExecute(gradeToExecute)
{
    if (gradeToSing < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSing > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : _name(src._name), _isSigned(src._isSigned),
        _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute){}

Form& Form::operator=(const Form& src)
{
    if (this != &src)
        this->_isSigned = src._isSigned;
    return *this;
}

Form::~Form(){}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

const int Form::getGradeToSign() const
{
    return _gradeToSign;
}

const int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}


const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high! (Highest possible is 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low! (Lowest possible is 150)";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form " << form.getName()
        << ", status: " << (form.getIsSigned() ? "signed" : "not signed")
        << ", sign grade: " << form.getGradeToSign()
        << ", exec grade: " << form.getGradeToExecute();
    return os;
}

