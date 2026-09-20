#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade is too low.");
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	if(this->_grade > 150)
		throw GradeTooLowException();
	else if(this->_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if(grade > 150)
		throw GradeTooLowException();
	else if(grade < 1)
		throw GradeTooHighException();
}
Bureaucrat::~Bureaucrat()
{
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

std::string Bureaucrat::getName() const
{
	return(this->_name);
}

void Bureaucrat::incrementGrade()
{
	if(this->_grade == 1)
		throw GradeTooHighException();
	else
		(this->_grade)--;
}

void Bureaucrat::decrementGrade()
{
	if(this->_grade == 150)
		throw GradeTooLowException();
	else
		(this->_grade)++;
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return(out);
}
