#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base(); // must be polymorphic to use dynamic_cast
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
