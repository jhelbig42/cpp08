#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span( void ) :
	_N(0)
	{}

Span::Span( int maxNbrs ) :
	_N(maxNbrs)
	{}

Span::Span( Span  const &other ):
	_N(other._N), _nbrs(other._nbrs)	
	{}

Span Span::operator=( Span const &other ){
	this->_N = other._N;
	this->_nbrs = other._nbrs;
	return (*this);
}

Span::~Span( void ){}

void Span::addNumber(int nbr){
	if ( _nbrs.size() == _N)
		throw (SpanIsFullException());
	_nbrs.push_back(nbr);
}

void Span::addNumbers(std::vector<int> toAdd){
	if (toAdd.size() + this->_nbrs.size() > this->_N)
		throw SpanIsFullException();
	this->_nbrs.insert(_nbrs.end(), toAdd.begin(), toAdd.end());
}

//needs at least 2 ints in vector
unsigned int	Span::shortestSpan( void ) const {
	if (this->_N < 2)
		throw SpanTooSmall();
	if (this->_nbrs.size() < 2)
		throw NotEnoughElementsInSpan();

	std::vector<int> tmp = this->_nbrs;
	std::sort(tmp.begin(), tmp.end()); // sort sorts ascending
	
	unsigned long shortest = tmp[1] - tmp[0];
	for (unsigned long i = 1; i < tmp.size() - 1; ++i){
		unsigned int test = tmp[i + 1] - tmp[i];
		if ( test < shortest)
			shortest = test;			
	}
	return (shortest);
}

unsigned long	Span::longestSpan( void ) const {
	if (this->_N < 2)
		throw SpanTooSmall();
	if (this->_nbrs.size() < 2)
		throw NotEnoughElementsInSpan();

	std::vector<int> tmp = this->_nbrs;
	std::sort(tmp.begin(), tmp.end()); // sort sorts ascending
	
	unsigned long longest = tmp[tmp.size() - 1] - tmp[0];
	
	return (longest);
}

std::vector<int> Span::getNbrs( void ) const {
	return(this->_nbrs);
}

std::ostream& operator<<(std::ostream &o, const Span &span){
	if (span.getNbrs().size() == 0){
		o << "vector within Span is empty" << std::endl;
		return(o);
	}
	for (unsigned long i = 0; i < (span.getNbrs()).size(); i++ ){
		o << (span.getNbrs())[i] << " ";
	}
	o << std::endl;
	return (o);
}
