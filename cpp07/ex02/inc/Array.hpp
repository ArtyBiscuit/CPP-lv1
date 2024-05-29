#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
    private:
        T *_array;
    public:
    Array    &Array::operator=(const Array &src){
        *this = src;
        return (*this);
    };
    Array(/* args */) : _array(NULL){};
    Array(unsigned int n){
        this->_array = new T[n];
    };
    Array(const Array &src){
        *this = src;
    };
    ~Array();
};


#endif