#include "Vector.hpp"
#include "Operators.hpp" 
#include "LinAlgMath.hpp"
#include <iostream>
#include <cassert>

// Tests an empty constructor for the general and specialized template cases
void testEmptyConstructor() 
{
    vec<int, 2> twoZeros; 
    vec<int, 4> fourZeros; 
    for(unsigned i = 0; i < 2; ++i) { assert(twoZeros.data[i] == 0); }
    for(unsigned i = 0; i < 4; ++i) { assert(fourZeros.data[i] == 0); }
    vec<char, 3> threeNullChars; 
    vec<char, 4> fourNullChars; 
    for(unsigned i = 0; i < 3; ++i) { assert(threeNullChars.data[i] == '\0'); }
    for(unsigned i = 0; i < 4; ++i) { assert(fourNullChars.data[i] == '\0'); }
}

// Test initializer list constructors for general and specialized template cases 
void testInitListConstructor() 
{
    vec<int, 3> a = {3, 4, 5}; 
    assert(a.data[0] == 3);
    assert(a.data[1] == 4);
    assert(a.data[2] == 5);

    vec<float, 4> b = {1.0f, 13.0f, 50.77f, 38.3f};
    assert(b.data[0] == 1.0f);
    assert(b.data[1] == 13.0f);
    assert(b.data[2] == 50.77f);
    assert(b.data[3] == 38.3f);
}

// Test single element init constructor 
void testSingleElementConstructor() 
{
    vec<int, 3> a(7.3); 
    for(unsigned i = 0; i < 2; ++i) { assert(a.data[i] == 7); }
    vec<float, 4> b(19.99f); 
    for(unsigned i = 0; i < 3; ++i) { assert(b.data[i] == 19.99f); }
}

int main() 
{
    std::cout << "Testing constructors...\n"; 
    testEmptyConstructor();
    testInitListConstructor();
    testSingleElementConstructor();

    // Checking SIMD 
    vec<float, 4> hopeVec;

    while(std::cin >> hopeVec)
    {
        std::cout << hopeVec;
        vec<float, 4> secVec = {2.0f, 3.0f, 1.0f, 2.0f};
        std::cout << dot(hopeVec, secVec) << '\n';
    }

    std::cout << "All Tests Pass!\n";
}

