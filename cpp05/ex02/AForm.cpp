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

std::string Form::getName(void) const
{
	return(this->_name);
}

bool Form::getIsSigned(void) const
{
	return(this->_isSigned);
}

int Form::getGradeToSign(void) const
{
	return(this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return(this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "Form: " << form.getName()
		<< ", signed: "	;

	if(form.getIsSigned())
		out << "yes";
	else
		out << "no";

	out << ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();

	return(out);
}

