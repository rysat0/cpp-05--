#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>

int main()
{
	std::cout << "----- Intern creates forms -----" << std::endl;

	AForm* shrubbery = NULL;
	AForm* robotomy = NULL;
	AForm* pardon = NULL;

	try
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);

		shrubbery = intern.makeForm("shrubbery creation", "intern_garden");
		robotomy = intern.makeForm("robotomy request", "Bender");
		pardon = intern.makeForm("presidential pardon", "Arthur");

		std::cout << "\nExecute created shrubbery form:" << std::endl;

		if(shrubbery != NULL)
		{
			std::cout << *shrubbery << std::endl;
			boss.signForm(*shrubbery);
			boss.executeForm(*shrubbery);
		}


		std::cout << "\nExecute created robotomy form:" << std::endl;
		if(robotomy != NULL)
		{
			std::cout << *robotomy << std::endl;
			boss.signForm(*robotomy);
			boss.executeForm(*robotomy);
		}


		std::cout << "\nExecute created pardon form:" << std::endl;
		if(pardon != NULL)
		{
			std::cout << *pardon << std::endl;
			boss.signForm(*pardon);
			boss.executeForm(*pardon);
		}
	}

	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete shrubbery;
	delete robotomy;
	delete pardon;



	std::cout << "\n----- Intern unknown form -----" << std::endl;

	AForm* unknown = NULL;

	try
	{
		Intern intern;

		unknown = intern.makeForm("coffee request", "Office");

		if(unknown == NULL)
			std::cout << "No form was created." << std::endl;
		else
			std::cout << *unknown << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete unknown;

	return(0);
}
