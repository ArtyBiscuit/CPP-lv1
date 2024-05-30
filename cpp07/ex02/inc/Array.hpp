#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include<exception>

template<typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:

        class OutOfRange : public std::exception { 
			public: 
				virtual const char* what() const throw() {
                    return ("Out of range.\n");
                }; 
		};

        Array    &Array::operator=(const Array &src){
            *this = src;
            return (*this);
        };

        T	&Array<T>::operator[](unsigned int index) const {
        	if (pos >= this->_size) {
        		throw OutOfRange();
        	}
        	return (this->_array[index]);
        }

        Array(/* args */) : _array(NULL), _size(0){};

        Array(unsigned int n){
            this->_array = new T[n];
            this->_size = n;
        };

        Array(const Array &src){
            *this = src;
        };

        ~Array();
};


#endif