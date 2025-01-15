#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
    srand(static_cast<unsigned int>(time(0)));
    unsigned int r = rand() % 3;
    switch (r)
    {
        case 0:
            return new A;
        case 1 :
            return new B;
        default:
            return new C;
    }    
}

void identify(Base* p){
    std::cout << "Pointers ....." << std::endl;
    if (dynamic_cast<A*>(p))
    {
        std::cout << "THIS A Class" << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p))
    {
        std::cout << "THIS B Class" << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p))
    {
        std::cout << "THIS C Class" << std::endl;
        return;
    }
}

void identify(Base& p){
    std::cout << "References ....." << std::endl;
    try{
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "THIS A Class" << std::endl;
        return;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try{
        B &a = dynamic_cast<B&>(p);
        (void)a;
        std::cout << "THIS B Class" << std::endl;
        return;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try{
        C &a = dynamic_cast<C&>(p);
        (void)a;
        std::cout << "THIS C Class" << std::endl;
        return;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main() {

    Base *p = generate();
    Base *p1 = new A;

    identify(p);
    identify(p1);
    identify(*p);

    delete p;
    delete p1;
    return 0;
}
