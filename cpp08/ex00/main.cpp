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



	std::cout << "\n----- First num search test -----" << std::endl;

	intResult = easyfind(nums, 1);

	if(intResult != nums.end())
		std::cout << "found: " << *intResult << std::endl;
	else
		std::cout << "Not found" << std::endl;


	std::cout << "\n----- last num search test -----" << std::endl;

	intResult = easyfind(nums, 999);

	if(intResult != nums.end())
		std::cout << "found: " << *intResult << std::endl;
	else
		std::cout << "Not found" << std::endl;



	std::cout << "\n----- non existing num search test -----" << std::endl;

	intResult = easyfind(nums, 500);

	if(intResult != nums.end())
		std::cout << "found: " << *intResult << std::endl;
	else
		std::cout << "Not found" << std::endl;


	std::list<int> numList;
	std::list<int>::iterator listIte;


	std::cout << "\n----- empty container test -----" << std::endl;
	listIte = easyfind(numList, 1);

	if(listIte != numList.end())
		std::cout << "found: " << *listIte << std::endl;
	else
		std::cout << "Not found" << std::endl;



	std::cout << "\n----- first occurrence test -----" << std::endl;

	numList.push_back(10);//begin()
	numList.push_back(100);
	numList.push_back(10);
	numList.push_back(5678);//end() - 1

	listIte = easyfind(numList, 10);

	if(listIte != numList.end())
	{
		std::cout << "found: " << *listIte << std::endl;
		if(listIte == numList.begin())
			std::cout << "first occurrence!" << std::endl;
	}
	else
		std::cout << "Not found" << std::endl;

	return(0);
}
