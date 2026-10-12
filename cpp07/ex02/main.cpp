#include "Array.hpp"

#include <string>
#include <iostream>

template <typename T>
void printInsideArray(const Array<T>& array)
{
	std::cout << "Size: " << array.size() << std::endl;

	if(array.size() == 0)
	{
		std::cout << "No element" << std::endl;
		return;
	}

	unsigned int i = 0;
	while(i < array.size())
	{
		std::cout << "Elements[" << i << "]: " << array[i] <<std::endl;
		++i;
	}
}

int main()
{

	unsigned int i = 0;


	std::cout << "----- 0 array test -----" << std::endl;
	Array<int> zeroArray;
	printInsideArray(zeroArray);


	std::cout << "\n----- n array test -----" << std::endl;
	Array<int> nArray(5);
	printInsideArray(nArray);

	while(i < nArray.size())
	{
		nArray[i] = static_cast<int>(i + 1);
		++i;
	}
	printInsideArray(nArray);


	std::cout << "\n----- copy constructor / deep copy test -----" << std::endl;
	// if value nArray has and value copiedArray are different, that means deep copied
	Array<int> copiedArray(nArray);

	nArray[0] = 42;

	std::cout << "Original: " << std::endl;
	printInsideArray(nArray);

	std::cout << "Copy: " << std::endl;
	printInsideArray(copiedArray);



	std::cout << "\n----- assignment operator test -----" << std::endl;
	Array<int> assignedArray(3);
	assignedArray = nArray;

	nArray[1] = 21;

	std::cout << "Original: " << std::endl;
	printInsideArray(nArray);

	std::cout << "Assigned: " << std::endl;
	printInsideArray(assignedArray);



	std::cout << "\n----- out of range(n) test -----" << std::endl;
	try
	{
		unsigned int arraySize = nArray.size();

		std::cout << nArray[arraySize] << std::endl;
		std::cout << "ERROR: exception was not thrown." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << '\n';
	}



	std::cout << "\n----- out of range(0) test -----" << std::endl;
	try
	{
		unsigned int arraySize = zeroArray.size();

		std::cout << zeroArray[arraySize] << std::endl;
		std::cout << "ERROR: exception was not thrown." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << '\n';
	}

	std::cout << "\n----- n strings array test -----" << std::endl;
	Array<std::string> nsArray(5);
	printInsideArray(nsArray);

	nsArray[0] = "Hey";
	nsArray[1] = "what's up";
	nsArray[2] = "my boy";
	nsArray[3] = "Are you down for Sauna tonight?";
	nsArray[4] = "I think John is gonna come.";
	printInsideArray(nsArray);


	return(0);
}
