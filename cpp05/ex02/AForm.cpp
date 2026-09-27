#include "AForm.hpp"
#include "Bureaucrat.hpp"


const char* AForm::GradeTooHighException::what() const throw()
{
	return("Grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade is too low.");
}

AForm::AForm() : _name("default AForm"), _isSigned(false), _gradeToSign(75), _gradeToExecute(50)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if(this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw GradeTooHighException();
	else if(this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
		this->_isSigned = other._isSigned;
	return(*this);
}

AForm::~AForm()
{
}

std::string AForm::getName(void) const
{
	return(this->_name);
}

bool AForm::getIsSigned(void) const
{
	return(this->_isSigned);
}

int AForm::getGradeToSign(void) const
{
	return(this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return(this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << "AForm: " << form.getName()
		<< ", signed: "	;

	if(form.getIsSigned())
		out << "yes";
	else
		out << "no";

	out << ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();

	return(out);
}

const char* AForm::NotSignedException::what() const throw()
{
	return("Form is not signed.");
}

void AForm::execute(const Bureaucrat& executor) const
{
	if(this->_isSigned == false)
		throw NotSignedException();

	else if(executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();

	this->executeAction();
}
