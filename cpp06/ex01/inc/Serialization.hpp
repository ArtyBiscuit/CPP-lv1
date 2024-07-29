#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &src);
		Serializer&	operator=(const Serializer &src);
    public:
        static uintptr_t	serialize(Data* ptr);
        static Data*   deserialize(uintptr_t raw);
};

#endif