#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <string>


//this function has to find the first occurrence of the second parameter in the first parameter.
//therefore return value must be iterator but type is still not determined so return value will be typename T::iterator
template <typename T>
typename T::iterator easyfind(T& container, int target);

#include "easyfind.tpp"


#endif
