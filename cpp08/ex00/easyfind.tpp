

//if it could find target -> returns first location that match to target
//if it couldn't find target -> returns container.end() automatically
template <typename T>
typename T::iterator easyfind(T& container, int target)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), target);
	return(it);
}
