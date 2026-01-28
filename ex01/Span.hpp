#pragma once

# include <vector>
# include <iostream>

class Span{
	private:
		unsigned int		_N;
		std::vector<int>	_nbrs;
	public:
		Span( void );
		Span( int maxNbrs );
		Span( Span const &other );
		Span operator=( const Span &other );
		~Span( void );

		void addNumber(int nbr);
		void addNumbers(std::vector<int> toAdd);
		unsigned int	shortestSpan() const;
		unsigned long	longestSpan() const;
		
		std::vector<int> getNbrs() const;

		class SpanIsFullException : public std::exception{
			virtual const char* what() const throw(){
				return("Span is already full");
			}
		};
		class NotEnoughElementsInSpan : public std::exception{
			virtual const char* what() const throw(){
				return("not enoughElements in Span (aka less than 2)");
			}
		};
		class SpanTooSmall : public std::exception{
			virtual const char* what() const throw(){
				return("Span too small (_N < 2)");
			}
		};
};

std::ostream& operator<<(std::ostream &o, const Span &span);