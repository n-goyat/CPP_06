#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base* generate() {
    int r = rand() % 3;

    if (r == 0) return new A;
    if (r == 1) return new B;
    return new C;
}

/*
    Identify the actual derived type of Base pointer
    using dynamic_cast
*/
void identify(Base *p) {
    if (dynamic_cast<A*>(p)) std::cout << "A\n";
    else if (dynamic_cast<B*>(p)) std::cout << "B\n";
    else if (dynamic_cast<C*>(p)) std::cout << "C\n";
}

/*
    Identify the actual derived type of Base reference
    using dynamic_cast and catching bad_cast exceptions
*/
void identify(Base &p) {
    try { A &a = dynamic_cast<A&>(p); (void)a; std::cout << "A\n"; return; }
    catch(...) {}

    try { B &b = dynamic_cast<B&>(p); (void)b; std::cout << "B\n"; return; }
    catch(...) {}

    try { C &c = dynamic_cast<C&>(p); (void)c; std::cout << "C\n"; return; }
    catch(...) {}
}
