#include <iostream>
#include <cxxabi.h>

// Just a class we will use for testing its type name.
class testClass {
    public:
        int anInteger;

        testClass(): anInteger(100) {};

        ~testClass() {};
};

int main () {
    // We will use these over and over.
    char* mangledName = nullptr;
    char* demangledName = nullptr;
    int status = 0;

    // Now for some demonstrations.

    auto x1 = 'a';
    std::cout << "x1 test ..." << std::endl;
    mangledName = const_cast<char*>(typeid(x1).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    std::cout << "Mangled: " << mangledName << std::endl;
    std::cout << "Demangled: " << demangledName << std::endl;
    std::cout << std::endl;

    auto x2 = testClass();
    std::cout << "x2 test ..." << std::endl;
    mangledName = const_cast<char*>(typeid(x2).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    std::cout << "Mangled: " << mangledName << std::endl;
    std::cout << "Demangled: " << demangledName << std::endl;
    std::cout << std::endl;

    auto x3 = x2.anInteger;
    std::cout << "x3 test ..." << std::endl;
    mangledName = const_cast<char*>(typeid(x3).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    std::cout << "Mangled: " << mangledName << std::endl;
    std::cout << "Demangled: " << demangledName << std::endl;
    std::cout << std::endl;

    auto x4 = L'a';
    std::cout << "x4 test ..." << std::endl;
    mangledName = const_cast<char*>(typeid(x4).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    std::cout << "Mangled: " << mangledName << std::endl;
    std::cout << "Demangled: " << demangledName << std::endl;
    std::cout << std::endl;

    auto x5 = "a";
    std::cout << "x5 test ..." << std::endl;
    mangledName = const_cast<char*>(typeid(x5).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    std::cout << "Mangled: " << mangledName << std::endl;
    std::cout << "Demangled: " << demangledName << std::endl;
    std::cout << std::endl;

    auto x6 = 10ULL;
    std::cout << "x6 test ..." << std::endl;
    mangledName = const_cast<char*>(typeid(x6).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    std::cout << "Mangled: " << mangledName << std::endl;
    std::cout << "Demangled: " << demangledName << std::endl;
    std::cout << std::endl;

    auto x7 = 10E-2;
    std::cout << "x7 test ..." << std::endl;
    mangledName = const_cast<char*>(typeid(x7).name());
    demangledName = abi::__cxa_demangle(mangledName, 0, 0, &status);
    std::cout << "Mangled: " << mangledName << std::endl;
    std::cout << "Demangled: " << demangledName << std::endl;
    std::cout << std::endl;

    return 0;
}

/*
    Revisions:
        > 2018-10-11 18:04:32, DevCrev(github.com/devcrev):
            > Creation.
            > We have 7 tests with this release.
*/


