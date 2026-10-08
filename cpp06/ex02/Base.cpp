#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <iostream>

Base::~Base()
{
}

Base* generate(void)
{
	int choice;

	choice = std::rand() % 3;

	if(choice == 0)
		return(new A);

	else if(choice == 1)
		return(new B);
	else
		return(new C);
}

void identify(Base *p)
{
	if(dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}
	if(dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}
	if(dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(...)
	{
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(...)
	{
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(...)
	{
	}

}
