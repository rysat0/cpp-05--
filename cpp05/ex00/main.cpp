#include "Bureaucrat.hpp"

int main()
{
	std::cout << "----- Normal Test Below -----" << std::endl;

	try
	{
		Bureaucrat def;

		std::cout << def << std::endl;

		def.incrementGrade();
		std::cout << "After increment: " << def << std::endl;

		def.decrementGrade();
		def.decrementGrade();
		std::cout << "After decrement: " << def << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		Bureaucrat alice("Alice", 50);

		std::cout << alice << std::endl;

		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;

		alice.decrementGrade();
		alice.decrementGrade();
		std::cout << "After decrement: " << alice << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat alice("Alice", 50);
		Bureaucrat john(alice);

		std::cout << alice << std::endl;
		std::cout << john << std::endl;

		john.incrementGrade();
		std::cout << "After increment: " << john << std::endl;

		john.decrementGrade();
		john.decrementGrade();
		std::cout << "After decrement: " << john << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat alice("Alice", 50);
		Bureaucrat nick("Nick", 99);
		nick = alice;

		std::cout << alice << std::endl;
		std::cout << nick << std::endl;

		nick.incrementGrade();
		std::cout << "After increment: " << nick << std::endl;

		nick.decrementGrade();
		nick.decrementGrade();
		std::cout << "After decrement: " << nick << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n----- Invalid test below -----" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tecca("Tecca", -3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat carti("Carti", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat dude("Dude", 1);
		std::cout << dude << std::endl;
		dude.incrementGrade();
		std::cout << dude << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tiernan("Tiernan", 150);
		std::cout << tiernan << std::endl;
		tiernan.decrementGrade();
		std::cout << tiernan << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	return(0);
}
