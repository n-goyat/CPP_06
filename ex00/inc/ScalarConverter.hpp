#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {
private:
    ScalarConverter(); // no instantiation

public:
    static void convert(const std::string &literal);

    // Helpers
    static bool isChar(const std::string &s);
    static bool isInt(const std::string &s);
    static bool isFloat(const std::string &s);
    static bool isDouble(const std::string &s);

    static void printChar(double d);
    static void printInt(double d);
    static void printFloat(double d);
    static void printDouble(double d);
};

#endif
