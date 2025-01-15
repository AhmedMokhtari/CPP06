#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    ScalarConverter::convert(argv[argc - 1]);
    // ScalarConverter::convert("955");

    // std::string a = "955.25f";
    // std::stringstream ss;

    // float f;

    // ss << a;
    // ss >> f;
    // std::cout << f << std::endl;
    return 0;
}