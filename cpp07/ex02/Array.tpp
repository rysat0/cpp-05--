

template <typename T>
Array<T>::Array() : _elements(NULL), _len(0)
{
}

// new T[n]() allocate 'n' elements that have 'T' type, and all are initialized by '()'
template <typename T>
Array<T>::Array(unsigned int n): _elements(new T[n] ()), _len(n)
{
}

template <typename T>
Array<T>::Array(const Array<T>& other) :_elements(new T[other._len]), _len(other._len)
{
    try
    {
        unsigned int i = 0;

	    while(i < other._len)
	    {
	    	this->_elements[i] = other._elements[i];
	    	++i;
	    }
    }
    catch(...)
    {
        delete[] this->_elements;
        throw;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if(this == &other)
		return(*this);

	T* newElements = new T[other._len];

    try
    {
        unsigned int i = 0;

	    while(i < other._len)
        {
            newElements[i] = other._elements[i];
            i++;
        }
    }
    catch(...)
    {
        delete[] newElements;
        throw;
    }

    delete[] this->_elements;
    this->_elements = newElements;
    this->_len = other._len;

    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if(index >= this->_len)
        throw std::exception();
    return this->_elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if(index >= this->_len)
        throw std::exception();
    return(this->_elements[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->_len);
}
