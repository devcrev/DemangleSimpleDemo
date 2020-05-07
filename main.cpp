#include <iostream>
#include <cxxabi.h>

// Just a class we will use for testing its type name.
class testClass {
    public:
        int anInteger;

        testClass(): anInteger(100) {};

        ~testClass() {};
};

void display (const char * title, char * mangledName, char * demangledName) {
    std::cout << title << std::endl;
    std::cout << "Mangled: " << mangledName << std::endl;
    std::cout << "Demangled: " << demangledName << std::endl;
    std::cout << std::endl;
}

int main () {
    // We will use these over and over.
    char * mangledName = nullptr;
    char * demangledName = nullptr;
    int status = 0;

    // Now for some demonstrations.

    auto x1 = 'a';
    mangledName = const_cast<char *>(typeid(x1).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    display ("x1 test ...", mangledName, demangledName);

    auto x2 = testClass();
    mangledName = const_cast<char *>(typeid(x2).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    display ("x2 test ...", mangledName, demangledName);

    auto x3 = x2.anInteger;
    mangledName = const_cast<char *>(typeid(x3).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    display ("x3 test ...", mangledName, demangledName);

    auto x4 = L'a';
    mangledName = const_cast<char *>(typeid(x4).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    display ("x4 test ...", mangledName, demangledName);

    auto x5 = "a";
    mangledName = const_cast<char *>(typeid(x5).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    display ("x5 test ...", mangledName, demangledName);

    auto x6 = 10ULL;
    mangledName = const_cast<char *>(typeid(x6).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    display ("x6 test ...", mangledName, demangledName);

    auto x7 = 10E-2;
    mangledName = const_cast<char *>(typeid(x7).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    display ("x7 test ...", mangledName, demangledName);

    return 0;
}

/*
    Revisions:
        > 2018-10-11 18:04:32, DevCrev(github.com/devcrev):
            > Creation.
            > We have 7 tests with this release.
        > 2020-05-07 17:07:09, DevCrev(github.com/devcrev):
            > Refactored code that outputs results.
*/
