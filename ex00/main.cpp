#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>

int main (void){
	std::list<int> list1;

	srand(time(NULL));

	for (int i = 0; i < 10000; ++i){
		list1.push_back(rand() % 10000);
	}

	std::list<int>::iterator pos = easyfind(list1, 3);
	if (pos == list1.end())
		std::cout << "element not found" << std::endl;
	else
		std::cout << *pos << std::endl;
}