#include <iostream>
#include "Serializer.hpp"

int main() {
    Data d;
    d.x = 42;
    d.msg = "Serialized";

    uintptr_t raw = Serializer::serialize(&d);
    Data *ptr = Serializer::deserialize(raw);

    std::cout << "Original:  " << &d << " -> " << d.msg << "\n";
    std::cout << "Recovered: " << ptr << " -> " << ptr->msg << "\n";

    return 0;
}
