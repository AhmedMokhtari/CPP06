#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cerrno>
#include <climits>
#include <cfloat>


class ScalarConverter{
    private:
        ScalarConverter();
        static void convert_int(int a, bool is_overflow);
        static void convert_flaot(float a, bool is_overflow, bool is_nan_inf);
        static void convert_double(double a, bool is_overflow, bool is_nan_inf);
        static bool is_all_num(const std::string &str);
        static bool is_valid(const std::string &str);
        static void hand_inf_nan(const std::string &str);
    public:
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &cp);
        ScalarConverter& operator=(const ScalarConverter &cp);
        static void convert(const std::string str);
};