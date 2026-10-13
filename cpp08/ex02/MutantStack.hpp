#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <iostream>
#include <deque>


// T: element type to be stored
// container: std::stackはそれ自体が要素を保存していない。vectorなどが指定された場合にはそれを内部コンテナとして保管する。

/*
MutantStack<int, std::vector<int> >
なら
T         = int
Container = std::vector<int>
になり、

Container::iteratorはstd::vector<int>::iteratorと等しい

*/
// inherit std::stack let us to use std::stack standard functions
//dequeはdouble ended queueの略で、前後から触れるque。この場合は指定なしの場合のデフォコンテナをdequeとしている。
// std::stack自体が2つのテンプレート引数があるのでここでも2つ指定して継承している
//
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;

		reverse_iterator rbegin();
		reverse_iterator rend();

		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"


# endif


/*
std::stack LIFO type stack, like piling dishes up

stack offer functions below

.push()
.pop()
.top()
.size()
.empty()

doesn't offer
.begin()
.end()

*/
