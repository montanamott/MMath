#ifndef LINEAR_ALG_MATH
#define LINEAR_ALG_MATH

#include "vector.hpp"

// Generalized dot product
template <typename T, int N> 
T dot(const vec<T, N>& vec1, const vec<T, N> vec2)
{
    T total(0); 
    for(unsigned i = 0; i < N; ++i) 
    { total += vec1.data[i]*vec2.data[i]; }
    return total;
}

#endif