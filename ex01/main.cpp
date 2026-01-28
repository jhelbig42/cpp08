#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int	main( void ){
	try{
		std::cout << "--- Test 1 ---" << std::endl;
		Span s(5);
		s.addNumber(1);
		s.addNumber(7);
		s.addNumber(1001);
		s.addNumber(13);
		s.addNumber(11);
		std::cout << "Shortest Span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << s.longestSpan() << std::endl;
		s.addNumber(0);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << "--- Test 2 ---" << std::endl;
		srand(time(NULL));
		Span s2(9999);
		std::vector<int> v;
		for (unsigned int i = 0; i < 5000; ++i)
			v.push_back(rand() % 100);
		//std::cout << s2;
		s2.addNumbers(v);
		//std::cout << s2;
		std::cout << "Shortest Span: " << s2.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << s2.longestSpan() << std::endl;
		s2.addNumbers(v);
		std::cout << "size of vector in Span: " << s2.getNbrs().size() << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}