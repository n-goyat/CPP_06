#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

/*
    Detect char literal like: 'a'
*/
bool ScalarConverter::isChar(const std::string &s) {
    return (s.length() == 1 && !isdigit(s[0]));
}

/*
    Detect integer
*/
bool ScalarConverter::isInt(const std::string &s) {
    char *end;
    strtol(s.c_str(), &end, 10);
    return (*end == '\0');
}

/*
    Detect float literal with trailing 'f'
*/
bool ScalarConverter::isFloat(const std::string &s) {
    if (s == "nanf" || s == "+inff" || s == "-inff")
        return true;
    char *end;
    strtof(s.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0');
}

/*
    Detect double literal
*/
bool ScalarConverter::isDouble(const std::string &s) {
    if (s == "nan" || s == "+inf" || s == "-inf")
        return true;
    char *end;
    strtod(s.c_str(), &end);
    return (*end == '\0');
}

/*
    Conversion entry point
*/
void ScalarConverter::convert(const std::string &s) {
    double val;

    if (isChar(s))
        val = static_cast<double>(s[0]);
    else if (isInt(s))
        val = static_cast<double>(atoi(s.c_str()));
    else if (isFloat(s))
        val = static_cast<double>(strtof(s.c_str(), NULL));
    else if (isDouble(s))
        val = strtod(s.c_str(), NULL);
    else {
        std::cout << "Invalid literal\n";
        return;
    }

    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}

void ScalarConverter::printChar(double d) {
    std::cout << "char: ";
    if (d < 0 || d > 127)
        std::cout << "impossible\n";
    else if (!isprint(static_cast<int>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'\n";
}

void ScalarConverter::printInt(double d) {
    std::cout << "int: ";
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(d) << "\n";
}

void ScalarConverter::printFloat(double d) {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f\n";
}

void ScalarConverter::printDouble(double d) {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << d << "\n";
}
