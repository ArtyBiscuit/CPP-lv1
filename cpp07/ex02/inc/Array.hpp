#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:

        class OutOfRange : public std::exception{ 
			public: 
				virtual const char* what() const throw(){
                    return ("Out of range.\n");
                }; 
		};

        const Array<T>    operator=(const Array<T> &src) const{
            *this = src;
            *this->_array = new T[src._size];
            for (unsigned int i = 0; i < src._size; i++){
                this->_array[i] = src._array[i]; 
            }
            return (*this);
        };

        T	operator[](unsigned int index) const {
            if (index >= this->_size) {
                throw OutOfRange();
            }
            return (this->_array[index]);
        };

        T	&operator[](unsigned int index){
            if (index >= this->_size) {
                throw OutOfRange();
            }
            return (this->_array[index]);
        };

        Array(/* args */) : _array(NULL), _size(0){};

        Array(unsigned int n){
            this->_array = new T[n];
            this->_size = n;
        };

        Array(const Array &src){
            *this = src;
        };

        ~Array(){
            delete this->_array;
        };
};



#endif