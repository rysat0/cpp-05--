#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat alice("Alice", 2);
    std::cout << alice << std::endl;
    alice.incrementGrade();
    std::cout << alice << std::endl;
    alice.decrementGrade();
    std::cout << alice << std::endl;

    Bureaucrat copy(alice);
    Bureaucrat assigned;
    assigned = alice;
    std::cout << "Copy: " << copy << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;

    try
    {
        std::cout << "Creating Bob with grade 0" << std::endl;
        Bureaucrat bob("Bob", 0);
        std::cout << "Bob was created" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat carol("Carol", 151);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    Bureaucrat top("Top", 1);
    try
    {
        top.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << top << std::endl;

    Bureaucrat bottom("Bottom", 150);
    try
    {
        bottom.decrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << bottom << std::endl;

    return 0;
}
