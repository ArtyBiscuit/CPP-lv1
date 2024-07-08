#include "Span.hpp"

void Span::addNumber(int Number){
    if (this->_VSpan.size() == (size_t)this->_N)
        throw SpanFull();
    this->_VSpan.push_back(Number);
}

unsigned int Span::longestSpan(){
    if (this->_VSpan.size() <= 1)
        throw SpanInsuficienteNumbers();
    
    int min = *std::min_element(this->_VSpan.begin(), this->_VSpan.end());
    int max = *std::max_element(this->_VSpan.begin(), this->_VSpan.end());
     return ((min - max) * -1);
}

unsigned int Span::shortestSpan(){

    if (this->_VSpan.size() <= 1)
        throw SpanInsuficienteNumbers();
    
    std::vector<int> SortSpan = this->_VSpan;
    std::sort(SortSpan.begin(), SortSpan.end());
     return ((SortSpan[0] - SortSpan[1]) * -1);
}


int generateUniqueInt(){
    int randInt = rand() % 2147483647;
    return (randInt);
}

void Span::randomGenerate(){
	srand((unsigned) time(0));

    std::vector<int> tmp_span (this->_N);
    std::generate(tmp_span.begin(), tmp_span.end(), generateUniqueInt);

    this->_VSpan = tmp_span;

}

Span::Span(unsigned int N){
    this->_N = N;
}

Span::Span(){
}

Span::~Span()
{
}