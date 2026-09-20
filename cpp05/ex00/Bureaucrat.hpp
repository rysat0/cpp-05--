#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <exception>

class Bureaucrat
{
	private:
		const std::string name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat& operator = (const Bureaucrat &other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

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

std::ostream& operator << (std::ostream& out, const Bureaucrat& bureaucrat);


# endif
