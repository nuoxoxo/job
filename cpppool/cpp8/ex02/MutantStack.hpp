#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include "iostream"
# include "deque"
# include "stack"

// definition in cppreference
// template<class T, class Container = std::deque<T>> class stack;

template <typename T>
class 	MutantStack : public std::stack<T>
{
public:
	// ------ Canon ------ //

	MutantStack();
	MutantStack(const MutantStack &);
	MutantStack & operator = (const MutantStack &);
	~MutantStack();

	// ------ Methods ------ //

	// we inherited std::stack we don't need prototyping
	/*
	unsigned int	size() const;
	void		push(T);
	void		pop();
	bool		empty() const;
	const T &	top( void ) const;
	*/

	// ------ Iterators ------ //

	typename std::deque<T>::iterator		begin();
	typename std::deque<T>::iterator		end();
	typename std::deque<T>::reverse_iterator	rbegin();
	typename std::deque<T>::reverse_iterator	rend();

	typename std::deque<T>::const_iterator		begin() const;
	typename std::deque<T>::const_iterator		end() const;
	typename std::deque<T>::const_reverse_iterator	rbegin() const;
	typename std::deque<T>::const_reverse_iterator	rend() const;

	// use `typedef` to save us from verbosity
	typedef typename std::deque<T>::iterator
		iterator;
	typedef typename std::deque<T>::reverse_iterator
		reverse_iterator;

	typedef typename std::deque<T>::const_iterator
		const_iterator;
	typedef typename std::deque<T>::const_reverse_iterator
		const_reverse_iterator;

	/*
	iterator		begin();
	iterator		end();
	reverse_iterator	rbegin();
	reverse_iterator	rend();
	const_iterator		begin() const;
	const_iterator		end() const;
	const_reverse_iterator	rbegin() const;
	const_reverse_iterator	rend() const;
	*/
};

# include "MutantStack.tpp"

// ************* what do we need *************
// 
// push
// pop
// top
// size
// begin
// endi
// 
/*
mstack.push(5);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
*/

#endif
