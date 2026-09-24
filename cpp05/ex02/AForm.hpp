#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:

		const std::string	_name;
		bool 				_isSigned;
		const int			_gradeToSign;
		const int 			_gradeToExecute;

	public:

		Form();
		Form(const Form& other);
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form& operator=(const Form& other);
		~Form();

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

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

std::ostream& operator<<(std::ostream& out, const Form& form);


# endif
