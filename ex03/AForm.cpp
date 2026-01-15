#include "AForm.hpp"

AForm::AForm(): _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){}

AForm::AForm(const std::string& name, int gradeToSing, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSing), _gradeToExecute(gradeToExecute)
{
    if (gradeToSing < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSing > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) : _name(src._name), _isSigned(src._isSigned),
        _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute){}

AForm& AForm::operator=(const AForm& src)
{
    if (this != &src)
        this->_isSigned = src._isSigned;
    return *this;
}

AForm::~AForm(){}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

const int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

const int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}


const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high! (Highest possible is 1)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low! (Lowest possible is 150)";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form " << form.getName()
        << ", status: " << (form.getIsSigned() ? "signed" : "not signed")
        << ", sign grade: " << form.getGradeToSign()
        << ", exec grade: " << form.getGradeToExecute();
    return os;
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->_isSigned == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
}
