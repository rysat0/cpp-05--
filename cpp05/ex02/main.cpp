#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "----- Default forms -----" << std::endl;

	try
	{
		ShrubberyCreationForm shrubbery;
		RobotomyRequestForm robotomy;
		PresidentialPardonForm pardon;

		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}



	std::cout << "\n----- ShrubberyCreationForm -----" << std::endl;

	try
	{
		ShrubberyCreationForm form("home");

		Bureaucrat badSigner("BadSigner", 146);
		Bureaucrat signer("Signer", 145);
		Bureaucrat badExecutor("BadExecutor", 138);
		Bureaucrat executor("Executor", 137);

		std::cout << form << std::endl;

		std::cout << "\nExecute unsigned form:" << std::endl;
		executor.executeForm(form);

		std::cout << "\nSign with insufficient grade:" << std::endl;
		badSigner.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\nSign at exact grade:" << std::endl;
		signer.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\nExecute with insufficient grade:" << std::endl;
		badExecutor.executeForm(form);

		std::cout << "\nExecute at exact grade:" << std::endl;
		executor.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n----- RobotomyRequestForm -----" << std::endl;

	try
	{
		RobotomyRequestForm form("Bender");

		Bureaucrat badSigner("BadSigner", 73);
		Bureaucrat signer("Signer", 72);
		Bureaucrat badExecutor("BadExecutor", 46);
		Bureaucrat executor("Executor", 45);

		std::cout << form << std::endl;

		std::cout << "\nExecute unsigned form:" << std::endl;
		executor.executeForm(form);

		std::cout << "\nSign with insufficient grade:" << std::endl;
		badSigner.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\nSign at exact grade:" << std::endl;
		signer.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\nExecute with insufficient grade:" << std::endl;
		badExecutor.executeForm(form);

		std::cout << "\nExecute at exact grade:" << std::endl;
		executor.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n----- PresidentialPardonForm -----" << std::endl;

	try
	{
		PresidentialPardonForm form("Arthur");

		Bureaucrat badSigner("BadSigner", 26);
		Bureaucrat signer("Signer", 25);
		Bureaucrat badExecutor("BadExecutor", 6);
		Bureaucrat executor("Executor", 5);

		std::cout << form << std::endl;

		std::cout << "\nExecute unsigned form:" << std::endl;
		executor.executeForm(form);

		std::cout << "\nSign with insufficient grade:" << std::endl;
		badSigner.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\nSign at exact grade:" << std::endl;
		signer.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\nExecute with insufficient grade:" << std::endl;
		badExecutor.executeForm(form);

		std::cout << "\nExecute at exact grade:" << std::endl;
		executor.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n----- Robotomy repeated execution -----" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm form("Marvin");

		boss.signForm(form);

		for(int i = 0; i < 10; i++)
		{
			std::cout << "\nAttempt " << i + 1 << ":" << std::endl;
			boss.executeForm(form);
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n----- Shrubbery copy and assignment -----" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm original("garden");
		ShrubberyCreationForm assigned("old_garden");

		boss.signForm(original);

		ShrubberyCreationForm copied(original);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copied: " << copied << std::endl;
		std::cout << "Before assignment: " << assigned << std::endl;

		assigned = original;

		std::cout << "After assignment: " << assigned << std::endl;

		boss.executeForm(copied);
		boss.executeForm(assigned);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n----- Robotomy copy and assignment -----" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm original("Bender");
		RobotomyRequestForm assigned("OldTarget");

		boss.signForm(original);

		RobotomyRequestForm copied(original);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copied: " << copied << std::endl;
		std::cout << "Before assignment: " << assigned << std::endl;

		assigned = original;

		std::cout << "After assignment: " << assigned << std::endl;

		boss.executeForm(copied);
		boss.executeForm(assigned);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n----- Pardon copy and assignment -----" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm original("Arthur");
		PresidentialPardonForm assigned("Ford");

		boss.signForm(original);

		PresidentialPardonForm copied(original);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copied: " << copied << std::endl;
		std::cout << "Before assignment: " << assigned << std::endl;

		assigned = original;

		std::cout << "After assignment: " << assigned << std::endl;

		boss.executeForm(copied);
		boss.executeForm(assigned);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n----- Execute through AForm pointer -----" << std::endl;

	AForm* form = NULL;

	try
	{
		Bureaucrat boss("Boss", 1);

		form = new PresidentialPardonForm("Trillian");

		std::cout << *form << std::endl;

		boss.signForm(*form);
		boss.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete form;

	return(0);
}
