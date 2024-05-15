#ifndef ITER_HPP
# define ITER_HPP


class TestClass{
    public:
        int     id;
        bool    status;
};

template<typename T>
void iter(T *tab, size_t size,void (&pf)(T&)){
    for(size_t i = 0; i < size; i++){
        pf(tab[i]);
    }
}

template<typename T>
void increase(T &input){
    std::cout << "old: " << input;
    input += 1;
    std::cout << ", new: " << input << std::endl;
}

template<typename T>
void setStatus(T &input){
    std::cout << "class: " << input.id << ", actual status: " << input.status;
    if (input.status)
        input.status = false;
    else
        input.status = true;
    std::cout << ", new status: " << input.status << std::endl;
}

template<typename T>
void checkStatus(T &input){
    std::cout << "class: " << input.id << ", status: " << input.status << std::endl;
}

template<typename T>
void checkValue(T &input){
        std::cout << "actual value: " << input << std::endl;
}

#endif