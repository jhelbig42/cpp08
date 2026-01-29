#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "--- Test 1 - MutantStack --- " << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "iterating through the stack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "--- Test 2 - List --- " << std::endl;
	std::list<int> list1;
	list1.push_back(5);
	list1.push_back(17);
	std::cout << "top: " << list1.back() << std::endl;
	list1.pop_back();
	std::cout << "size: " << list1.size() << std::endl;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(737);
	list1.push_back(0);
	std::list<int>::iterator it1 = list1.begin();
	std::list<int>::iterator ite1 = list1.end();
	++it1;
	--it1;
	std::cout << "iterating through the list: " << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	return 0;
}
