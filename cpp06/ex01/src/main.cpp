#include "Serialization.hpp"
#include <iostream>

int main(void){
    Data myData;

    myData.name = "is a test";

    std::cout << "Base addr: " << &myData << " | data: " << myData.name << std::endl;

    uintptr_t ptr_one = Serializer::serialize(&myData);
    std::cout << "serialize addr: " << &ptr_one << std::endl;
    Data *ptr_tow = Serializer::deserialize(ptr_one);
    std::cout << "deserialize addr: " << ptr_tow << " | Deserialize Data: " << ptr_tow->name << std::endl;
    return (0);
}