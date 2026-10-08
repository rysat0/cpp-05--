#include "iter.hpp"


#include <iostream>
#include <string>



template <typename T>
void printElement(const T& element)
{
	std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T& element)
{
	++element;
}

void doubleValue(int& value)
{
	value *= 2;
}


int main()
{
	int nums[] = {0,1,2,3,4,5};
	std::string words[] = {"hey", "what's up", "dude", "you", "good?"};
	const int connums[] = {100, 99, 98, 97};

	int onenum[] = {42};

	std::cout << "----- nums test -----" << std::endl;

	::iter(nums, (sizeof(nums) / sizeof(nums[0])), printElement<int>);

	std::cout << "\n----- after increment nums -----" << std::endl;

	::iter(nums, (sizeof(nums) / sizeof(nums[0])), incrementElement<int>);
	::iter(nums, (sizeof(nums) / sizeof(nums[0])), printElement<int>);


	std::cout << "----- words test -----" << std::endl;
	::iter(words, (sizeof(words) / sizeof(words[0])), printElement<std::string>);


	std::cout << "----- const nums test -----" << std::endl;
	::iter(connums, (sizeof(connums) / sizeof(connums[0])), printElement<int>);

	std::cout << "----- zero test -----" << std::endl;
	::iter(onenum, 0, printElement<int>);

	std::cout << "----- just one test -----" << std::endl;
	::iter(onenum, 1, printElement<int>);

	std::cout << "----- normal function test -----" << std::endl;
	::iter(nums, (sizeof(nums) / sizeof(nums[0])), doubleValue);
	::iter(nums, (sizeof(nums) / sizeof(nums[0])), printElement<int>);


	return(0);
}
