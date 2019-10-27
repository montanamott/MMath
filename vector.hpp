#ifndef VECTOR_CLASS
#define VECTOR_CLASS

#include <iostream> 

// Generic N-dimensional vector
template <typename T, int N> 
struct vec {
    T data[N];

    explicit vec(const T single) {
        for(unsigned i = 0; i < N; ++i) 
        { data[i] = single; }
    }

    vec(const std::initializer_list<T> list) {
        for(unsigned i = 0; i < N; ++i) 
        { data[i] = list.begin()[i]; }
    }

    vec() {
        for(unsigned i = 0; i < N; ++i) 
        { data[i] = T(); }
    }
};

// Specialized, 4 component vector
template <typename T> struct vec<T, 4> {
    union {
        T data[4]; 
        struct {T x, y, z, w; }; 
        struct {T r, g, b, a; };
    };

    explicit vec(const T single) {
        for(unsigned i = 0; i < 4; ++i) 
        { data[i] = single; }
    }

    vec(const std::initializer_list<T> list) {
        for(unsigned i = 0; i < 4; ++i) 
        { data[i] = list.begin()[i]; }
    }

    vec() {
        for(unsigned i = 0; i < 4; ++i) 
        { data[i] = T(); }
    }
};

#endif