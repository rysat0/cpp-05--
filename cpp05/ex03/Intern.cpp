#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

typedef AForm* (*CreateFunction)(const std::string&);

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return(*this);
}

static AForm* createShrubbery(const std::string& target)
{
	return(new ShrubberyCreationForm(target));
}

static AForm* createRobotomy(const std::string& target)
{
	return(new RobotomyRequestForm(target));
}

static AForm* createPardon(const std::string& target)
{
	return(new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string&formName, const std::string& target) const
{

	int i = 0;

	const std::string names[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	CreateFunction creators[3] =
	{
		createShrubbery,
		createRobotomy,
		createPardon
	};

	while(i < 3)
	{
		if(formName == names[i])
		{
			AForm* form = creators[i](target);

			std::cout << "Intern creates " << form->getName() << std::endl;
			return(form);
		}
		i++;
	}
	std::cout << "Intern couldn't create form: unknown name \"" << formName << "\"." << std::endl;
	return(NULL);
}
