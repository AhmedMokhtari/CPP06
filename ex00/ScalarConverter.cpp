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

void convert_int(int a)
{
    if (a < ' ' || a > 126)
        std::cout << "char : "   << "Non displayable"  << std::endl;
    else
        std::cout << "char : "   << static_cast<char>(a)  << std::endl;
    std::cout << "int : "    << static_cast<int>(a) << std::endl;
    std::cout << "float : "  << std::fixed  << std::setprecision(1) << static_cast<float>(a) << "f" <<  std::endl;
    std::cout << "double : " << std::fixed  << std::setprecision(1) << static_cast<double>(a) << std::endl;
}
void convert_flaot(double a)
{
    if (a < ' ' || a > 126)
        std::cout << "char : "   << "Non displayable"  << std::endl;
    else
        std::cout << "char : "   << static_cast<char>(a)  << std::endl;
    if (a)
        std::cout << "int : "    << static_cast<int>(a) << std::endl;
    else
        std::cout << "int : "    << "impossible" << std::endl;
    std::cout << "float : "   << static_cast<float>(a) << "f" <<  std::endl;
    std::cout << "double : "  << static_cast<double>(a) << std::endl;
}

bool is_all_num(const std::string &str)
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

bool is_valid(const std::string &str)
{
    bool has_point = false;

    size_t i = 0;
    size_t len = str.size();
    if (str[0] == '-')
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
        if (!std::isdigit(str[i]) && str[i] != 'f' && i != len - 1)
            return false; // invalid arg
        i++;
    }
    return true;
}

void ScalarConverter::convert(const std::string str){
    if (str.size() == 1 && std::isalpha(str[0]))
    {
        convert_int(str[0]);
    }else if (is_all_num(str)){
        int tmp;
        std::stringstream ss;
        ss << str;
        ss >> tmp;
        convert_int(tmp);
    }
    else if(!str.compare("nan"))
    {
        // size_t t = 0xfff0000000000001;
        convert_flaot(sqrt(-2));
    }
    else if (is_valid(str))
    {
        double tmp;
        std::stringstream ss;
        ss << str;
        ss >> tmp;
        convert_flaot(tmp);
    }
}