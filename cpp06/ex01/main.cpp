#include "Serializer.hpp"

#include <iostream>

int main()
{
	Data original;

	original.id = 42;
	original.name = "tiernan";

	uintptr_t raw;
	Data* restored;

	raw = Serializer::serialize(&original);
	restored = Serializer::deserialize(raw);

	std::cout << std::boolalpha;
	std::cout << "same address: " << (restored == &original) << std::endl;


	std::cout << "id: " << restored->id << std::endl;
	std::cout << "name: " << restored->name << std::endl;


	return(0);
}
