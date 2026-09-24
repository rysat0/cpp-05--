#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "----- Default form -----" << std::endl;

	try
	{
		 Form form;

		 std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Normal form -----" << std::endl;

	try
	{
		Form form("Application", 50, 25);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Grade 1 -----" << std::endl;

	try
	{
		Form form("Highest app", 1, 1);
		std::cout << form << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Grade 150 -----" << std::endl;

	try
	{
		Form form("Highest app", 150, 150);
		std::cout << form << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Sign Grade 0 -----" << std::endl;

	try
	{
		Form form("Invalid", 0, 50);
		std::cout << form << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Sign Grade 151 -----" << std::endl;

	try
	{
		Form form("Invalid", 151, 50);
		std::cout << form << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Execute Grade 0 -----" << std::endl;

	try
	{
		Form form("Invalid", 50, 0);
		std::cout << form << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Execute Grade 151 -----" << std::endl;

	try
	{
		Form form("Invalid", 50, 151);
		std::cout << form << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Sign failure -----" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 51);
		Form form("Application", 50, 25);

		std::cout << bob << std::endl;
		std::cout << "Before: " << form << std::endl;

		bob.signForm(form);

		std::cout << "After: " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Sign success at exact grade -----" << std::endl;

	try
	{
		Bureaucrat dude("Dude", 50);
		Form form("Application", 50, 25);

		std::cout << dude << std::endl;
		std::cout << "Before: " << form << std::endl;

		dude.signForm(form);

		std::cout << "After: " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Sign success with higher grade -----" << std::endl;

	try
	{
		Bureaucrat tiernan("Tiernan", 30);
		Form form("Application", 50, 25);

		std::cout << tiernan << std::endl;
		std::cout << "Before: " << form << std::endl;

		tiernan.signForm(form);

		std::cout << "After: " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Copy constructor -----" << std::endl;

	try
	{
		Bureaucrat alice("Alice", 30);
		Form original("original", 50, 25);

		alice.signForm(original);

		Form copied(original);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copied: " << copied << std::endl;


	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << "\n----- Assignment -----" << std::endl;

    try
    {
        Bureaucrat alice("Alice", 50);
        Form original("Original", 50, 25);
        Form assigned("Assigned", 100, 80);

        alice.signForm(original);

        std::cout << "Source: " << original << std::endl;
        std::cout << "Before: " << assigned << std::endl;

        assigned = original;

        std::cout << "After: " << assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

	return(0);
}
