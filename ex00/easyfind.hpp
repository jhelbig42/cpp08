#pragma once

#include <iostream>

class NotFoundException : public std::exception{
		public:
			virtual const char *what() const throw(){
				return ("Value not found");
			}
};

//for use with sequence containers: vector, list, deque
//Sequence containers implement data structures which can be accessed sequentially.

template<typename T_container>
typename T_container::iterator easyfind(T_container &container, int search_val){
	for( typename T_container::iterator it = container.begin(); it != container.end(); ++it){
		if (*it == search_val)
			return (it);
	}
	return (container.end());
}