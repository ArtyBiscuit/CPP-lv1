#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>

# include <vector>
# include <iterator>
# include <algorithm>

class Span
{
private:
    unsigned int _N;
    std::vector<int> _VSpan;
public:
    void addNumber(int Number);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    Span();
    Span(unsigned int N);
    ~Span();
    class SpanFull : public std::exception{ 
	public: 
		virtual const char* what() const throw(){
            return ("Span Full.");
        }; 
};
};

#endif