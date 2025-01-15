#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
class ScalarConverter{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &cp);
        ScalarConverter& operator=(const ScalarConverter &cp);
        static void convert(const std::string str);
};