#include "Vector.hpp"
#include "Operators.hpp" 
#include "LinAlgMath.hpp"
#include <iostream>
#include <cassert>

bool floatEq(float a, float b)
{
    if(a < b) return b - a < 0.00001f; 
    return a - b < 0.00001f; 
}

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

void testMultiElementConstructor() 
{
    vec<int, 2> a(0, 1); 
    for(unsigned i = 0; i < 2; ++i) { assert(a.data[i] == i); }

    vec<int, 3> b(0, 1, 2); 
    for(unsigned i = 0; i < 3; ++i) { assert(b.data[i] == i); }

    vec<int, 4> c(0, 1, 2, 3); 
    for(unsigned i = 0; i < 4; ++i) { assert(c.data[i] == i); }
}

void testDotProduct() 
{
    vec<float, 4> a = {1.0f, 2.0f, 3.0f, 4.0f}; 
    vec<float, 4> b = {4.0f, 3.0f, 2.0f, 1.0f}; 
    assert(dot(a, b) == 20.0f); 

    vec<float, 5> c = {1.0f, 2.0f, 3.0f, 4.0f, 1.0f}; 
    vec<float, 5> d = {4.0f, 3.0f, 2.0f, 1.0f, -1.0f}; 
    assert(floatEq(dot(c, d), 19.0f));

}

void testCrossProduct()
{
    vec<int, 3> a = {1, 2, 3}; 
    vec<int, 3> b = {3, 4, 5};
    vec<int, 3> res = cross(a, b); 

    assert(res.x == -2); 
    assert(res.y == 4);
    assert(res.z == -2);
}

int main() 
{
    std::cout << "Testing constructors...\n"; 
    testEmptyConstructor();
    testInitListConstructor();
    testSingleElementConstructor();
    testMultiElementConstructor();

    std::cout << "Testing math functions...\n";
    testDotProduct();
    testCrossProduct();

    std::cout << "All Tests Pass!\n";
}

