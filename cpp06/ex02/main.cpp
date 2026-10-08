#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>


int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int i = 0;

	A a;
	B b;
	C c;

	std::cout << "\n----- Direct Test -----" << std::endl;

	identify(&a);
	identify(a);

	std::cout << std::endl;

	identify(&b);
	identify(b);

	std::cout << std::endl;

	identify(&c);
	identify(c);

	std::cout << "\n----- Generated Test -----" << std::endl;

	while(i < 10)
	{
		Base *generated = generate();

		identify(generated);
		identify(*generated);

		std::cout << std::endl;

		delete generated;
		i++;
	}

	return(0);
}
