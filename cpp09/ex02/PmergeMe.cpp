#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(), _deque()
{
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if(this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return(*this);
}

PmergeMe::~PmergeMe()
{
}


namespace
{
	int parsePositiveInteger(const std::string& text)
	{
		if(text.empty())
			throw std::runtime_error("Error: empty argument");

		int value = 0;
		std::string::size_type i = 0;

		while(i < text.size())
		{
			if(text[i] < '0' || text[i] > '9')
				throw std::runtime_error("Error: invalid input");

			int digit = text[i] - '0';

			if(value > (INT_MAX - digit) / 10)
				throw std::runtime_error("Error: integer overflow");

			value = value * 10 + digit;
			++i;
		}
		if(value == 0)
			throw std::runtime_error("Error: value must be positive");

		return(value);
	}

}


// chain内->識別番号
// this->_vector[chain[middle]] -> 識別番号に対応する実際の値
void PmergeMe::insertVectorIndex(std::vector<std::size_t>& chain, std::size_t index, std::size_t bound) const
{
	std::size_t left = 0;
	std::size_t right = bound;

	while(left < right)
	{
		std::size_t middle = left + (right - left) / 2;

		if(this->_vector[chain[middle]] < this->_vector[index])
			left = middle + 1;
		else
			right = middle;
	}
	chain.insert(chain.begin() + left, index);
}


// indices -> prural form of index
// this function handle "index of each number in original vector", not the original number itself
// returns vector that contains sorted indices
// last const means this function won't change original vector contains original numbers
std::vector<std::size_t> PmergeMe::sortVectorIndices(const std::vector<std::size_t>& indices) const
{
	// index is 0 or 1 -> already sorted
	if(indices.size() < 2)
		return(indices);

	// "larger" memorizes larger nums in each pair comparison
	std::vector<std::size_t> larger;
	// "partner" memorize smaller nums by using larger num for index of this vector
	std::vector<std::size_t> partner(this->_vector.size());
	std::size_t i = 0;
	std::size_t tmp = 0;

	// compare nums between 2 (with num next to num now), memorize "which is larger", "what num is partner(comparison opponent)"
	while(i + 1 < indices.size())
	{
		std::size_t small = indices[i];
		std::size_t large = indices[i + 1];


		if(this->_vector[small] > this->_vector[large])
		{
			tmp = small;
			small = large;
			large = tmp;
		}

		larger.push_back(large);
		partner[large] = small;
		i += 2;
	}

	// recursive call to sort "larger" side til larger.size() become under 2 -> larger sorted
	larger = sortVectorIndices(larger);

	std::vector<std::size_t> pending;
	i = 0;

	while(i < larger.size())
	{
		// adding small nums by sorted large num indices
		pending.push_back(partner[larger[i]]);
		++i;
	}

	// odd num -> there is one num doesn't have pair -> add to pending
	// .back() retuens last elements of that vector
	if(indices.size() % 2 == 1)
		pending.push_back(indices.back());

	// chain -> copied vector from sorted large nums
	// insert small num(first num in pending) before smallest num in larger vector
	std::vector<std::size_t> chain(larger);
	chain.insert(chain.begin(), pending[0]);

	//"previous" -> Up to which element (index) of the "small vector" has the insertion into the "chain" been completed
	//"current" -> In this comparison, up to which index within the "small vector" should be included as a target for comparison
	std::size_t previous = 1;
	std::size_t current = 3;
	std::size_t end;

	// still has to compare nums or not
	//ヤコブスタール数の計算による、前の周で比較できるpending[]の最大のIndexがpreviousに入るので、それが実際のサイズを上回ったら全比較完了
	while(previous < pending.size())
	{
		end = current;
		//比較回数最適化の際にヤコブスタール数に則りグループ分けを行い、内側のループでそのグループ分けされた要素数全て比較しようとするので、実際に存在するIndex数で切り詰めないと要素外アクセスが発生する
		if(end > pending.size())
			end = pending.size();

		i = end;
		while(i > previous)
		{
			// "pending" -> 今回挿入したい要素のIndex
			//"bound" -> The end of the search range in a binary search
			std::size_t position = i - 1;
			std::size_t bound = chain.size();

			// if pair is existing
			if(position < larger.size())
			{
				bound = 0;
				// search what index does partner have -> will become end of binary search
				while(bound < chain.size() && chain[bound] != larger[position])
					++bound;
			}
			insertVectorIndex(chain, pending[position], bound);
			--i;
		}
		if(end == pending.size())
			break;
		// use Jacobsthal number to make clculate more faster ... J[0] = 0, J[1] = 1, J[n] = J[n-1] + 2*J[n-2]
		std::size_t next = current + 2 * previous;
		previous = current;
		current = next;
	}
	return(chain);

}

void PmergeMe::sortVector()
{
	std::vector<std::size_t> indices;
	std::size_t i = 0;

	while(i < this->_vector.size())
	{
		// Indexの配列を用意
		indices.push_back(i);
		++i;
	}

	indices = sortVectorIndices(indices);

	std::vector<int> sorted;
	i = 0;

	while(i < indices.size())
	{
		//添字配列からそれに対応していたオリジナルの配列の数値に戻す
		sorted.push_back(this->_vector[indices[i]]);
		++i;
	}

	this->_vector.swap(sorted);

}
void PmergeMe::sortDeque()
{

}

void PmergeMe::loadVector(int argc, char **argv)
{
	this->_vector.clear();
	int i = 1;
	int value = 0;

	while(i < argc)
	{
		value = parsePositiveInteger(argv[i]);
		this->_vector.push_back(value);
		++i;
	}
}
void PmergeMe::loadDeque(int argc, char **argv)
{
	this->_deque.clear();
	int i = 1;
	int value = 0;

	while(i < argc)
	{
		value = parsePositiveInteger(argv[i]);
		this->_deque.push_back(value);
		++i;
	}
}

void PmergeMe::run(int argc, char **argv)
{
}
