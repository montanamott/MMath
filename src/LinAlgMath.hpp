#ifndef LINEAR_ALG_MATH
#define LINEAR_ALG_MATH

#include "vector.hpp"

// Generalized DOT PRODUCT
template <typename T, int N> 
T dot(const vec<T, N>& vec1, const vec<T, N> vec2)
{
    T total(0); 
    for(unsigned i = 0; i < N; ++i) 
    { total += vec1.data[i]*vec2.data[i]; }
    return total;
}

// Specialized 4-Vector DOT PRODUCT
template <typename T> 
T dot(const vec<T, 4>& a, const vec<T, 4> b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

// Specialized 3-Vector DOT PRODUCT
template <typename T> 
T dot(const vec<T, 3>& a, const vec<T, 3> b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

// Specialized 2-Vector DOT PRODUCT
template <typename T> 
T dot(const vec<T, 2>& a, const vec<T, 2> b)
{
    return a.x*b.x + a.y*b.y;
}

// Specialized 3-Vector CROSS PRODUCT
// Potential TODO: Might make this use SSE intrinsics since the assembly for this is... not good. 
template <typename T> 
vec<T, 3>  cross(const vec<T, 3>& a, const vec<T, 3> b)
{
    return vec<T, 3>(a.y*b.z - a.z*b.y, 
            a.z*b.x - a.x*b.z, 
            a.x*b.y - a.y*b.x); 
}

#endif