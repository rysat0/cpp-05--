#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>

template <typename Element, typename Function>
void iter(Element *array, const std::size_t len, Function function)
{
	std::size_t i = 0;

	while(i < len)
	{
		function(array[i]);
		i++;
	}

}



#endif
