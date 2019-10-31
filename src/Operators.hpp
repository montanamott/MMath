#ifndef OPERATORS 
#define OPERATORS

#include "Vector.hpp"

// Generalized element wise multiplication 
template <typename T, int N> 
vec<T, N> operator*(const vec<T, N>& vec1, const vec<T, N>& vec2)
{
    vec<T, N> result(); 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = vec1.data[i]*vec2.data[i]; }
    return result;
}

// Overloading general ostream operator
template <typename T, int N> 
std::ostream & operator<<(std::ostream& out, const vec<T, N>& vec)
{ 
    std::cout << "{ ";
    for(unsigned i = 0; i < N; ++i) 
    { 
        out << vec.data[i]; 
        out << ' ';
    }
    std::cout << "} ";

    return out;
}

// Overloading general istream operator 
template <typename T, int N> 
std::istream & operator>>(std::istream& in, vec<T, N>& vec)
{ 
    unsigned i = 0; 
    while(i < N && in >> vec.data[i])
    { ++i; }

    return in;
}

#endif