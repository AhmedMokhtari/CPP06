#pragma once
#include <iostream>
#include <cstdio>
#include <stdint.h>
#include "Data.hpp"

class Serializer{
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& cp);
        Serializer& operator=(const Serializer &cp);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};