#include <iostream>
#include <ctime>
#include "Base.hpp"

int main() {
    std::srand(time(NULL));

    Base *ptr = generate();

    std::cout << "Identify by pointer: ";
    identify(ptr);

    std::cout << "Identify by reference: ";
    identify(*ptr);

    delete ptr;
}
