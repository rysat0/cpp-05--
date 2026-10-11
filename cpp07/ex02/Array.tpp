

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
	unsigned int i = 0;

	while(i < other._len)
	{
		this->_elements[i] = other._elements[i];
		++i;
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if(other == this)
		return(this);
	this->_elements = new T[this->_len];

	unsigned int i = 0;

	while(i < this->_elements)

}


template <typename T>
Array<T>::Array()
    : elements(NULL), len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
    : elements(/* n個確保して値初期化 */), len(n)
{
}

template <typename T>
Array<T>::Array(const Array<T>& other)
    : elements(/* other.len個確保 */), len(other.len)
{
    // 全要素をコピー
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    // 自己代入を確認
    // 新しい領域を確保
    // 全要素をコピー
    // 古い領域を解放
    // elementsとlenを更新

    return *this;
}

template <typename T>
Array<T>::~Array()
{
    // delete[]
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    // index >= lenなら例外
    // elements[index]を返す
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    // index >= lenなら例外
    // elements[index]を返す
}

template <typename T>
unsigned int Array<T>::size() const
{
    // lenを返す
}
