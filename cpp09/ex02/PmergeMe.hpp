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

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void run(int argc, char **argv);

};

# endif
