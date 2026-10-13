#include "MutantStack.hpp"

#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <algorithm>


template <typename It>
void printRange(It first, It last)
{
	while(first != last)
	{
		std::cout << *first << " ";
		++first;
	}
	std::cout << std::endl;
}

int main()
{

	std::cout << std::boolalpha;
	// 1/0 -> true/false


	std::cout << "----- Subject example test -----" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top expected: 17 / Actual: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size expected: 1 / Actual: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << "Expected: 5 3 5 737 0" << std::endl;
	printRange(it, ite);

	std::stack<int> s(mstack);
	std::cout << "Copied stack size expected: 5 / Actual: " << s.size() << std::endl;
	std::cout << "Copied stack top expected: 0 / Actual: " << s.top() << std::endl;


	std::cout << "\n----- std::list comparison test -----" << std::endl;
	std::list<int> numList;
	numList.push_back(5);
	numList.push_back(17);

	std::cout << "Back expected: 17 / Actual: " << numList.back() << std::endl;
	numList.pop_back();
	std::cout << "Size expected: 1 / Actual: " << numList.size() << std::endl;

	numList.push_back(3);
	numList.push_back(5);
	numList.push_back(737);
	numList.push_back(0);

	std::list<int>::iterator listIt = numList.begin();
	++listIt;
	--listIt;
	std::cout << "Expected: 5 3 5 737 0" << std::endl;
	printRange(listIt, numList.end());


	bool same;
	same = ((mstack.size() == numList.size()) && std::equal(mstack.begin(), mstack.end(), numList.begin()));
	std::cout << "Same elements expected: true / Actual: " << same << std::endl;

	std::cout << "\n----- Empty stack test -----" << std::endl;
	MutantStack<int> emptyStack;
	std::cout << "Empty expected: true / Actual: " << emptyStack.empty() << std::endl;
	std::cout << "Size expected: 0 / Actual: " << emptyStack.size() << std::endl;
	std::cout << "begin == end expected: true / Actual: " << (emptyStack.begin() == emptyStack.end()) << std::endl;
	std::cout << "rbegin == rend expected: true / Actual: " << (emptyStack.rbegin() == emptyStack.rend()) << std::endl;


	emptyStack.push(42);
	std::cout << "Top expected: 42 / Actual: " << emptyStack.top() << std::endl;
	std::cout << "Empty expected: false / Actual: " << emptyStack.empty() << std::endl;
	emptyStack.pop();
	std::cout << "Empty after pop expected: true / Actual: " << emptyStack.empty() << std::endl;


	std::cout << "\n----- Iterator movement / modification test -----" << std::endl;
	MutantStack<int> nums;
	nums.push(10);
	nums.push(20);
	nums.push(30);

	it = nums.begin();
	std::cout << "First expected: 10 / Actual: " << *it << std::endl;
	++it;
	std::cout << "Next expected: 20 / Actual: " << *it << std::endl;
	--it;
	std::cout << "Previous expected: 10 / Actual: " << *it << std::endl;
	*it = 42;

	std::cout << "Expected: 42 20 30" << std::endl;
	printRange(nums.begin(), nums.end());


	std::cout << "\n----- Reverse iterator test -----" << std::endl;
	std::cout << "Expected: 30 20 42" << std::endl;
	printRange(nums.rbegin(), nums.rend());


	MutantStack<int>::reverse_iterator reverseIt = nums.rbegin();
	*reverseIt = 99;
	std::cout << "Top after modification expected: 99 / Actual: " << nums.top() << std::endl;


	std::cout << "\n----- Const iterator test -----" << std::endl;
	const MutantStack<int>& constNums = nums;
	std::cout << "Forward expected: 42 20 99" << std::endl;
	printRange(constNums.begin(), constNums.end());
	std::cout << "Reverse expected: 99 20 42" << std::endl;
	printRange(constNums.rbegin(), constNums.rend());


	std::cout << "\n----- Copy constructor / Assignment test -----" << std::endl;
	MutantStack<int> copied(nums);
	MutantStack<int> assigned;
	assigned.push(-1);
	assigned.push(-2);
	assigned = constNums;

	nums.top() = 100;
	*copied.begin() = -10;
	assigned.pop();

	std::cout << "Original expected: 42 20 100" << std::endl;
	printRange(nums.begin(), nums.end());
	std::cout << "Copy expected: -10 20 99" << std::endl;
	printRange(copied.begin(), copied.end());
	std::cout << "Assigned expected: 42 20" << std::endl;
	printRange(assigned.begin(), assigned.end());


	std::cout << "\n----- Self assignment test -----" << std::endl;
	MutantStack<int>& sameStack = nums;
	nums = sameStack;
	std::cout << "Expected: unchanged, 42 20 100" << std::endl;
	printRange(nums.begin(), nums.end());


	std::cout << "\n----- LIFO test -----" << std::endl;
	std::cout << "Expected: 100 20 42" << std::endl;
	while(!nums.empty())
	{
		std::cout << nums.top() << " ";
		nums.pop();
	}
	std::cout << std::endl;
	std::cout << "Size expected: 0 / Actual: " << nums.size() << std::endl;


	std::cout << "\n----- Vector as internal container test -----" << std::endl;
	MutantStack<int, std::vector<int> > vectorStack;
	vectorStack.push(1);
	vectorStack.push(2);
	vectorStack.push(3);

	std::cout << "Forward expected: 1 2 3" << std::endl;
	printRange(vectorStack.begin(), vectorStack.end());
	std::cout << "Reverse expected: 3 2 1" << std::endl;
	printRange(vectorStack.rbegin(), vectorStack.rend());


	return 0;
}
