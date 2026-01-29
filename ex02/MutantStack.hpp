#pragma once

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack( void );
		MutantStack( MutantStack const &other);
		MutantStack& operator=(MutantStack const &other);
		~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator iterator;
		
		iterator begin();
		
		iterator end();
};

#include "MutantStack.tpp"