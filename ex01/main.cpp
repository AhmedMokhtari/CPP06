#include "Serializer.hpp"

int main()
{
    Data a;

    Data *p = &a;
    uintptr_t t = Serializer::serialize(p);

    Data *p1 = Serializer::deserialize(t);


    if (p1 == p)
        std::cout << "The Adress are the Same" << std::endl;
    return 0;
}