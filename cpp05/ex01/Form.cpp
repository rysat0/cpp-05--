#include "Form.hpp"
#include "Bureaucrat.hpp"


const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade is too low.");
}

Form::Form() : _name("default form"), _isSigned(false), _gradeToSign(75), _gradeToExecute(50)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if(this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw GradeTooHighException();
	else if(this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
	if(this != &other)
		this->_isSigned = other._isSigned;
	return(*this);
}

Form::~Form()
{
}


