#include <string>
#include <iostream>
#include <cstdlib>

#include "iter.hpp"


void noConstTest(void){
    int array_size = 3;


    int int_array[array_size];
    for(int i = 0; i < array_size; i++){
        int_array[i] = 0;
    }
    ::iter(int_array, array_size, increase);
    ::iter(int_array, array_size, increase);
    ::iter(int_array, array_size, increase);
    std::cout << std::endl;


    char char_array[array_size];
    for(int i = 0; i < array_size; i++){
        char_array[i] = 'a';
    }
    ::iter(char_array, array_size, increase);
    ::iter(char_array, array_size, increase);
    ::iter(char_array, array_size, increase);
    std::cout << std::endl;


    float float_array[array_size];
    for(int i = 0; i < array_size; i++){
        float_array[i] = 0.1;
    }
    ::iter(float_array, array_size, increase);
    ::iter(float_array, array_size, increase);
    ::iter(float_array, array_size, increase);
    std::cout << std::endl;


    TestClass class_Array[array_size];
    for(int i = 0; i < array_size; i++){
        class_Array[i].status = false;
        class_Array[i].id = i;
    }
    ::iter(class_Array, array_size, setStatus);
    ::iter(class_Array, array_size, setStatus);
    ::iter(class_Array, array_size, setStatus); 
    std::cout << std::endl;
}

void constTest(void){
    int array_size = 3;


    int int_array[array_size];
    for(int i = 0; i < array_size; i++){
        int_array[i] = i;
    }
    const int *c_int_array = int_array;
    ::iter(c_int_array, array_size, checkValue);
    ::iter(c_int_array, array_size, checkValue);
    ::iter(c_int_array, array_size, checkValue);
    std::cout << std::endl;


    char char_array[array_size];
    for(int i = 0; i < array_size; i++){
        char_array[i] = 'a' + i;
    }
    const char *c_char_array = char_array;
    ::iter(c_char_array, array_size, checkValue);
    ::iter(c_char_array, array_size, checkValue);
    ::iter(c_char_array, array_size, checkValue);
    std::cout << std::endl;


    float float_array[array_size];
    for(int i = 0; i < array_size; i++){
        float_array[i] = 0.1 + i;
    }
    const float *c_float_array = float_array;
    ::iter(c_float_array, array_size, checkValue);
    ::iter(c_float_array, array_size, checkValue);
    ::iter(c_float_array, array_size, checkValue);
    std::cout << std::endl;


    TestClass class_Array[array_size];
    for(int i = 0; i < array_size; i++){
        class_Array[i].status = false;
        class_Array[i].id = i;
    }
    const TestClass *c_class_Array = class_Array;
    ::iter(c_class_Array, array_size, checkStatus);
    ::iter(c_class_Array, array_size, checkStatus);
    ::iter(c_class_Array, array_size, checkStatus); 
    std::cout << std::endl;
}

int main(void){
    noConstTest();
    constTest();
	return 0;
}