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

        Array<T>    &operator=(const Array<T> &src){
            if(this != &src){
                if (this->_size > 0)
                    delete [] this->_array;
                this->_array = new T[src._size] ();
                for (unsigned int i = 0; i < src._size; i++){
                    this->_array[i] = src._array[i]; 
                }
                this->_size = src._size;
            }
            return (*this);
        };

        //Array &operator=(const Array &toCopy) {
        //     if (this == &toCopy)
        //         return (*this);
        //     delete [] _array;
        //     this->_array = new T[toCopy.size()];
        //     this->_size = toCopy.size();
        //     for (unsigned int i = 0; i < toCopy.size(); i++)
        //         this->_array[i] = toCopy._array[i];
        //     return (*this);
        // };

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
            return (this->_array[(int)index]);
        };

        Array() : _array(NULL), _size(0){};

        Array(unsigned int n){
            this->_array = new T[n] ();
            this->_size = n;
        };

        Array(const Array &src){
            this->_array = new T[src._size] ();
            this->_size = src._size;
            for (unsigned int i = 0; i < src._size; i++){
                this->_array[i] = src._array[i]; 
            }
        };

        ~Array(){
            delete [] this->_array;
        };
};



#endif