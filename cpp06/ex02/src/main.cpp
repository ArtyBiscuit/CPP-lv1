#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

Base* generate(void){
	srand((unsigned) time(NULL));
	int random = rand() % 3;

    switch (random){
        case 0:
            std::cout << "Generating a type class A." << std::endl;
            return(new A);
            break;
        case 1:
            std::cout << "Generating a type class B." << std::endl;
            return(new B);
            break;
        case 2:
            std::cout << "Generating a type class C." << std::endl;
            return(new C);
            break;
        default:
            std::cout << "No class generated." << std::endl;
            break;
    }
    return (0);
}

void identify(Base* p){
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "is a A class" << std::endl;
    else if(dynamic_cast<B*>(p) != NULL)
        std::cout << "is a B class" << std::endl;
    else if(dynamic_cast<C*>(p) != NULL)
        std::cout << "is a C class" << std::endl;
    else
        std::cout << "not identified" << std::endl;
}

void identify(Base& p){
	try{
		A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "is a A class" << std::endl;
		return;
	}
    catch(const std::exception &e){
    }
	try{
		B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "is a B class" << std::endl;
		return;
	}
    catch(const std::exception &e){
    }
	try{
		C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "is a c class" << std::endl;
		return;
	}
    catch(const std::exception &e){
    }
	std::cout << "not identified" << std::endl;
}

int main(void){
	Base	*MyClass = generate();

	identify(MyClass);
	identify(*MyClass);

	delete MyClass;
	return 0;
}