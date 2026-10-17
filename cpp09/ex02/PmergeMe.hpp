#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <climits>
#include <stdexcept>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		void loadVector(int argc, char **argv);
		void loadDeque(int argc, char **argv);

		void sortVector();
		void sortDeque();

		std::vector<std::size_t> sortVectorIndices(const std::vector<std::size_t>& indices) const;
		void insertVectorIndex(std::vector<std::size_t>& chain, std::size_t index, std::size_t bound) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void run(int argc, char **argv);

};

# endif
