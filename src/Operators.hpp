#ifndef OPERATORS 
#define OPERATORS

#include "Vector.hpp"
#include "Point.hpp"

// The typical pattern here is that operators are element-wise (if you have MATLAB experience, think .*)
// This might seem annoying -- particulary for not having * be dot product -- but I'm prioritizing consistency since it's
// within the bounds of reason. 

// Note: For element-wise operations below, most compilers seem to optimize the same way
// whether private members or data arrays are used (meaning I don't need to duplicate code for specific length vectors)


// --- Operators on one VECTOR --- // 

// Scalar multiplication of a vector 
template <typename T, int N> 
vec<T, N> operator*(const T scal, const vec<T, N>& v2)
{
    vec<T, N> result; 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = scal * v2.data[i]; }
    return result;
}

template <typename T, int N> 
vec<T, N> operator*(const vec<T, N>& v2, const T scal)
{
    vec<T, N> result; 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = scal * v2.data[i]; }
    return result;
}

// --- Operators between two VECTORS --- //

// Generalized element-wise MULTIPLICATION
template <typename T, int N> 
vec<T, N> operator*(const vec<T, N>& v1, const vec<T, N>& v2)
{
    vec<T, N> result; 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = v1.data[i] * v2.data[i]; }
    return result;
}

// Generalized element-wise ADDITION
template <typename T, int N> 
vec<T, N> operator+(const vec<T, N>& v1, const vec<T, N>& v2)
{
    vec<T, N> result; 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = v1.data[i] + v2.data[i]; }
    return result;
}

// Generalized element-wise DIVISION 
// Note: For now, dividing by 0 should be handled by the user
template <typename T, int N> 
vec<T, N> operator/(const vec<T, N>& v1, const vec<T, N>& v2)
{
    vec<T, N> result; 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = v1.data[i] / v2.data[i]; }
    return result;
}

// Generalized element-wise SUBTRACTION
template <typename T, int N> 
vec<T, N> operator-(const vec<T, N>& v1, const vec<T, N>& v2)
{
    vec<T, N> result; 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = v1.data[i] - v2.data[i]; }
    return result;
}


// Overloading general ostream operator
template <typename T, int N> 
std::ostream & operator<<(std::ostream& out, const vec<T, N>& vect)
{ 
    out << "{ ";
    for(unsigned i = 0; i < N; ++i) 
    { 
        out << vect.data[i]; 
        out << ' ';
    }
    out << "} ";

    return out;
}

template <typename T, int N> 
std::ostream & operator<<(std::ostream& out, const point<T, N>& pnt)
{ 
    out << "{ ";
    for(unsigned i = 0; i < N; ++i) 
    { 
        out << pnt.data[i]; 
        out << ' ';
    }
    out << "} ";

    return out;
}

// Overloading general istream operator 
template <typename T, int N> 
std::istream & operator>>(std::istream& in, vec<T, N>& vect)
{ 
    unsigned i = 0; 
    while(i < N && in >> vect.data[i])
    { ++i; }

    return in;
}

template <typename T, int N> 
std::istream & operator>>(std::istream& in, point<T, N>& pnt)
{ 
    unsigned i = 0; 
    while(i < N && in >> pnt.data[i])
    { ++i; }

    return in;
}

// --- Operators between POINTS --- //

// Point - Point
template <typename T, int N> 
vec<T, N> operator-(const point<T, N>& p1, const point<T, N>& p2)
{
    vec<T, N> result; 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = p1.data[i] - p2.data[i]; }
    return result;
}

// --- Operators between POINTS and VECTORS --- // 

// Point + Vector
template <typename T, int N> 
point<T, N> operator+(const point<T, N>& pnt, const vec<T, N>& vect)
{
    point<T, N> result; 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = pnt.data[i] + vect.data[i]; }
    return result;
}

// Vector + Point
template <typename T, int N> 
point<T, N> operator+(const vec<T, N>& vect, const point<T, N>& pnt)
{
    point<T, N> result; 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = pnt.data[i] + vect.data[i]; }
    return result;
}

// Point - Vector
template <typename T, int N> 
point<T, N> operator-(const point<T, N>& pnt, const vec<T, N>& vect)
{
    point<T, N> result; 
    for(unsigned i = 0; i < N; ++i)
    { result.data[i] = pnt.data[i] - vect.data[i]; }
    return result;
}



#endif