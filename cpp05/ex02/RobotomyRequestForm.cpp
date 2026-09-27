#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Drrrrrrrrrr.........." << std::endl;

	if(std::rand() % 2 == 0)
	{
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	}
	else{
		std::cout << "Robotomy failed for " << this->_target << "." << std::endl;
	}
}
