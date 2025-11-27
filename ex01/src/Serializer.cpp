#include "Serializer.hpp"

/*
    reinterpret_cast to convert pointer <-> integer
*/

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

/*
    reinterpret_cast to convert integer -> pointer
*/
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
