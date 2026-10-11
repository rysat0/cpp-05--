#ifndef ARRAY_HPP
# define ARRAY_HPP


template <typename T>
class Array
{
	private:
		T* _elements;
		unsigned int _len;

	public:
		Array(); // make empty array(0 element)
		Array(unsigned int n);	// allocate n elements by using new[]
		Array(const Array& other); // deep copy
		Array& operator=(const Array& other); // deep copy
		~Array(); // delete[]

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int size() const; // return number of elements
};



# include "Array.tpp"






# endif
