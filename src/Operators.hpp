#ifndef OPERATORS 
#define OPERATORS

#include "Vector.hpp"

// The typical pattern here is that operators are element-wise (if you have MATLAB experience, think .*)
// This might seem annoying -- particulary for not having * be dot product -- but I'm prioritizing consistency since it's
// within the bounds of reason. 

// Note: For element-wise operations below, most compilers seem to optimize the same way
// whether private members or data arrays are used (meaning I don't need to duplicate code for specific length vectors)


// Generalized element-wise MULTIPLICATION
template <typename T, int N> 
vec<T, N> operator*(const vec<T, N>& vec1, const vec<T, N>& vec2)
{
    vec<T, N> result(); 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = vec1.data[i] * vec2.data[i]; }
    return result;
}

// Generalized element-wise ADDITION
template <typename T, int N> 
vec<T, N> operator+(const vec<T, N>& vec1, const vec<T, N>& vec2)
{
    vec<T, N> result(); 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = vec1.data[i] + vec2.data[i]; }
    return result;
}

// Generalized element-wise DIVISION 
// Note: For now, dividing by 0 should be handled by the user
template <typename T, int N> 
vec<T, N> operator/(const vec<T, N>& vec1, const vec<T, N>& vec2)
{
    vec<T, N> result(); 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = vec1.data[i] / vec2.data[i]; }
    return result;
}

// Generalized element-wise SUBTRACTION
template <typename T, int N> 
vec<T, N> operator-(const vec<T, N>& vec1, const vec<T, N>& vec2)
{
    vec<T, N> result(); 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = vec1.data[i] - vec2.data[i]; }
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