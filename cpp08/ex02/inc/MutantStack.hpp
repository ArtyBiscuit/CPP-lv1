#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include<stack>
# include<iterator>

template<typename T>
class MutantStack : public std::stack<T>{
    public:

        typedef typename MutantStack<T>::container_type::iterator iterator;
        typedef typename MutantStack<T>::container_type::const_iterator const_iterator;

        iterator begin() {
            return this->c.begin();
        }

        iterator end() {
            return this->c.end();
        }

        const_iterator begin() const {
            return this->c.begin();
        }

        const_iterator end() const {
            return this->c.end();
        }

        MutantStack<T>(const MutantStack<T> &src) : std::stack<T>(src) {
            *this = src;
        }

        MutantStack<T>& operator=(const MutantStack<T> &rhs) {
            if (this != &rhs)
                this->std::stack<T>::operator=(rhs);
            return (*this);
        }

        MutantStack<T>() : std::stack<T>() {}
        ~MutantStack<T>() {}
};


#endif