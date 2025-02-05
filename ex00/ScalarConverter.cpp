#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){

}

ScalarConverter::~ScalarConverter(){

}

ScalarConverter::ScalarConverter(const ScalarConverter &cp){
    (void)cp;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &cp){
    (void )cp;
    return *this;
}

void  ScalarConverter::convert_int(int a, bool is_overflow)
{
    if(!is_overflow)
    {
        if (a < -128 || a > 127)
            std::cout << "char : "   << "Impossible"  << std::endl;
        else if (a < ' ' || a > 126)
            std::cout << "char : "   << "Non displayable"  << std::endl;
        else
            std::cout << "char : '"   << static_cast<char>(a)  << "'" <<std::endl;
        if (a > INT_MAX || a < INT_MIN)
            std::cout << "int : "   << "Impossible"  << std::endl;
        else
            std::cout << "int : "    << static_cast<int>(a) << std::endl;
        std::cout << "float : "  << std::fixed  << std::setprecision(1) << static_cast<float>(a) << "f" <<  std::endl;
        std::cout << "double : " << std::fixed  << std::setprecision(1) << static_cast<double>(a) << std::endl;
    }
    else
    {
        std::cout << "char : "   << "Impossible"  << std::endl;
        std::cout << "int : "    << "Impossible" << std::endl;
        std::cout << "float : "   << "Impossible"<<  std::endl;
        std::cout << "double : "  << "Impossible" << std::endl;
    }
}

// void ScalarConverter::convert_flaot(float a, bool is_overflow, bool is_nan_inf)
// {
//     if (!is_overflow)
//     {
//         if (a > 127 || a < -128)
//             std::cout << "char : "   << "Impossible"  << std::endl;
//         else if (is_nan_inf)
//             std::cout << "char : "   << "Impossible"  << std::endl;
//         else if (a < ' ' || a > 126)
//             std::cout << "char : "   << "Non displayable"  << std::endl;
//         else
//             std::cout << "char : "   << static_cast<char>(a)  << std::endl;
//         if (a > INT_MAX || a < INT_MIN)
//             std::cout << "int : "   << "Impossible"  << std::endl;
//         else if (is_nan_inf)
//             std::cout << "int : "   << "Impossible"  << std::endl;
//         else 
//             std::cout << "int : " << static_cast<int>(a) << std::endl;
//         printf("f is %f\n", static_cast<float>(a));
//         std::cout << "a is " << (a < FLT_MIN ) <<std::endl;
//         if (a > FLT_MAX || std::fabs(a) < FLT_MIN)
//             std::cout << "float : "   << "Impossible"  << std::endl;
//         else 
//             std::cout  << "float : "   << static_cast<float>(a) << "f" <<  std::endl;
//         std::cout  << "double : "  << static_cast<double>(a) << std::endl;
//     }
//     else
//     {
//         std::cout << "char : "   << "Impossible"  << std::endl;
//         std::cout << "int : "    << "Impossible" << std::endl;
//         std::cout << "float : "   << "Impossible"<<  std::endl;
//         std::cout << "double : "  << "Impossible" << std::endl;
//     }
   
// }

void ScalarConverter::convert_double(double a, bool is_overflow, bool is_nan_inf)
{
    if (!is_overflow)
    {
        if (a > 127 || a < -128)
            std::cout << "char : "   << "Impossible"  << std::endl;
        else if (is_nan_inf)
            std::cout << "char : "   << "Impossible"  << std::endl;
        else if (a < ' ' || a > 126)
            std::cout << "char : "   << "Non displayable"  << std::endl;
        else
            std::cout << "char : "   << static_cast<char>(a)  << std::endl;
        if (a > INT_MAX || a < INT_MIN || is_nan_inf)
            std::cout << "int : "   << "Impossible"  << std::endl;
        else 
            std::cout << "int : " << static_cast<int>(a) << std::endl;
        if (a > FLT_MAX || std::fabs(a) < FLT_MIN)
            std::cout << "float : "   << "Impossible"  << std::endl;
        else 
            std::cout << "float : "   << static_cast<float>(a) << "f" <<  std::endl;
        std::cout  << "double : "  <<a << std::endl;
    }
    else
    {
        std::cout << "char : "   << "Impossible"  << std::endl;
        std::cout << "int : "    << "Impossible" << std::endl;
        std::cout << "float : "   << "Impossible"<<  std::endl;
        std::cout << "double : "  << "Impossible" << std::endl;
    }
}

bool ScalarConverter::is_all_num(const std::string &str)
{
    int i = 0;
    if (str[0] == '-')
        i++;
    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::is_valid(const std::string &str)
{
    bool has_point = false;

    size_t i = 0;
    size_t len = str.size();
    if (str[0] == '-')
        i++;
    while (i < len)
    {
        if (str[i] == '.' && !has_point && i != 0 && i != len -1 && str[i - 1] != '-')
        {
             has_point = true;
            i++;
            continue;
        } 
        if (str[i] == '.')
            return false; 
        if (!std::isdigit(str[i]) && (str[i] != 'f' || i != len - 1 || !std::isdigit(str[i - 1])))
            return false;
        i++;
    }
    return true;
}
void ScalarConverter::hand_inf_nan(const std::string &str)
{
    std::cout << "char : "   << "Impossible"  << std::endl;
    std::cout << "int : "    << "Impossible" << std::endl;
    std::cout << "float : "   << str << "f" <<  std::endl;
    std::cout << "double : "  << str << std::endl;
}

void ScalarConverter::convert(const std::string str){
    if (str.size() == 1 && !std::isdigit(str[0]))
    {
        convert_int(str[0], 0);
    }else if (is_all_num(str)){
        int tmp;
        std::stringstream st;
        std::stringstream sw;
        st << str;
        st >> tmp;
        sw << tmp;
        convert_int(tmp, st.str() != sw.str());
    }
    else if (is_valid(str))
    {
        errno = 0;
        if (str[str.length() - 1] == 'f')
        {
            float a = strtof(str.c_str(), NULL);
            convert_double(a, errno == ERANGE, 0);
        }else
        {
            double a = strtod(str.c_str(), NULL);
            convert_double(a, errno == ERANGE, 0);
        } 
    }
    else if(!str.compare("nan") || !str.compare("nanf"))
    {
        hand_inf_nan("nan");
    }
    else if(!str.compare("+inf") || !str.compare("+inff"))
    {
        hand_inf_nan("+inf"); 
    }
    else if(!str.compare("-inf")  || !str.compare("-inff") )
    {
        hand_inf_nan("-inf"); 
    }else
        std::cout << "Invalid input \n";
}