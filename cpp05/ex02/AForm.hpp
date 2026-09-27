#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <cstdlib>

class Bureaucrat;

class AForm
{
	private:

		const std::string	_name;
		bool 				_isSigned;
		const int			_gradeToSign;
		const int 			_gradeToExecute;

	protected:
		virtual void executeAction() const = 0;

	public:

		AForm();
		AForm(const AForm& other);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(const Bureaucrat& bureaucrat);

		void execute(const Bureaucrat& executor) const;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const AForm& form);


# endif
