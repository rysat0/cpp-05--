#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

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

};


# endif
