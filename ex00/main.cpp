#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    ScalarConverter::convert(argv[argc - 1]);
    return 0;
}