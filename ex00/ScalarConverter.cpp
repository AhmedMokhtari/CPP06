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
        if (a < ' ' || a > 126)
            std::cout << "char : "   << "Non displayable"  << std::endl;
        else
            std::cout << "char : "   << static_cast<char>(a)  << std::endl;
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
void ScalarConverter::convert_flaot(double a, bool is_overflow, bool is_nan_inf)
{
    if (!is_overflow)
    {
        if (is_nan_inf)
            std::cout << "char : "   << "Impossible"  << std::endl;
        else if (a < ' ' || a > 126)
            std::cout << "char : "   << "Non displayable"  << std::endl;
        else
            std::cout << "char : "   << static_cast<char>(a)  << std::endl;
        if (is_nan_inf)
            std::cout << "int : "   << "Impossible"  << std::endl;
        else 
            std::cout << "int : "    << static_cast<int>(a) << std::endl;
        std::cout << "float : "   << static_cast<float>(a) << "f" <<  std::endl;
        std::cout << "double : "  << static_cast<double>(a) << std::endl;
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
        if (str[i] == '.' && !has_point)
        {
             has_point = true;
            i++;
            continue;
        } 
        if (str[i] == '.')
            return false; // invalid arg
        if (!std::isdigit(str[i]) && (str[i] != 'f' || i != len - 1))
            return false; // invalif arg
        i++;
    }
    return true;
}

void ScalarConverter::convert(const std::string str){
    if (str.size() == 1 && std::isalpha(str[0]))
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
            convert_flaot(a, errno == ERANGE, 0);
        }else
        {
            double a = strtod(str.c_str(), NULL);
            convert_flaot(a, errno == ERANGE, 0);
        } 
    }
    else if(!str.compare("nan") || !str.compare("nanf"))
    {
        convert_flaot(NAN, 0, 1);
    }
    else if(!str.compare("+inf"))
    {
        convert_flaot(INFINITY, 0, 1);
    }
    else if(!str.compare("-inf"))
    {
        convert_flaot(-INFINITY, 0, 1);
    }else
        std::cout << "Invalid input \n";
}