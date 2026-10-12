#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>


int main()
{
	std::vector<int> nums;

	nums.push_back(1);
	nums.push_back(20);
	nums.push_back(34);
	nums.push_back(42);
	nums.push_back(999);

	std::cout << "----- Normal search test -----" << std::endl;

	std::vector<int>::iterator intResult = easyfind(nums, 20);

	if(intResult != nums.end())
		std::cout << "found: " << *intResult << std::endl;
	else
		std::cout << "Not found" << std::endl;



	std::cout << "----- First num search test -----" << std::endl;

	intResult = easyfind(nums, 1);

	if(intResult != nums.end())
		std::cout << "found: " << *intResult << std::endl;
	else
		std::cout << "Not found" << std::endl;


	std::cout << "----- last num search test -----" << std::endl;

	intResult = easyfind(nums, 999);

	if(intResult != nums.end())
		std::cout << "found: " << *intResult << std::endl;
	else
		std::cout << "Not found" << std::endl;



	std::cout << "----- non existing num search test -----" << std::endl;

	intResult = easyfind(nums, 500);

	if(intResult != nums.end())
		std::cout << "found: " << *intResult << std::endl;
	else
		std::cout << "Not found" << std::endl;


	return(0);
}
