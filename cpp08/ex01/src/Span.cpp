#include "Span.hpp"

void Span::addNumber(int Number){
    if (this->_VSpan.size() == (size_t)this->_N)
        throw SpanFull();
    this->_VSpan.push_back(Number);
}

unsigned int Span::longestSpan(){
     int min = std::min(*this->_VSpan.begin(), *this->_VSpan.end());
     int max = std::max(*this->_VSpan.begin(), *this->_VSpan.end());

     std::cout << min << std::endl;
     std::cout << max << std::endl;
     return (0);
}

Span::Span(unsigned int N){
    this->_N = N;
}

Span::Span(){
}

Span::~Span()
{
}