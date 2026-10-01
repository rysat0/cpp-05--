#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename;

	filename = this->_target + "_shrubbery";

	std::ofstream file(filename.c_str());

	if (!file)
        throw std::runtime_error("Could not open shrubbery file.");

    file << "    *          *\n";
    file << "   ***        ***\n";
    file << "  *****      *****\n";
    file << " *******    *******\n";
    file << "    ||         ||\n";
    file << "    ||         ||\n";

    file.close();

    if (!file)
        throw std::runtime_error("Could not write shrubbery file.");
}
