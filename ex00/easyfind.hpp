#pragma once

#include <iostream>
#include <algorithm>

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
	return (std::find(container.begin(), container.end(), search_val));
}
