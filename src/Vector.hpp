#ifndef VECTOR_CLASS
#define VECTOR_CLASS

#include <iostream> 


// A vector is an element of some n-dimensional Euclidean vector-space. Each vector has an implicit origin of the 0 vector. 
// The vector spaces are implicity coordinatized by the standard basis vectors, e_1 , ..., e_n. 
// I'm making these mathematically rigorous distinctions because the goal for this library is to work with affine spaces,
// see the Point class for more information. 

// Note: The initializer list constructor is not the most efficient, so I suggest using it mainly for convenience/debugging pruposes. 
//       For 2-4 dim vectors, use the multi-element constructor instead. 

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

// Specialized, 2 component vector
template <typename T> struct vec<T, 2> {
    union {
        T data[2]; 
        struct {T x, y; }; 
    };

    explicit vec(const T single) {
        x = single; 
        y = single;
    }

    vec(const std::initializer_list<T> list) {
        x = list.begin()[0];
        y = list.begin()[1]; 
    }

    vec(const T x_in, const T y_in) {
        x = x_in; 
        y = y_in; 
    }

    vec() {
        x = T(); 
        y = T();
    }
};

// Specialized, 3 component vector
template <typename T> struct vec<T, 3> {
    union {
        T data[3]; 
        struct {T x, y, z; }; 
        struct {T r, g, b; };
    };

    explicit vec(const T single) {
        x = single; 
        y = single;
        z = single;
    }

    vec(const std::initializer_list<T> list) {
        x = list.begin()[0];
        y = list.begin()[1]; 
        z = list.begin()[2];
    }

    vec(const T x_in, const T y_in, const T z_in) {
        x = x_in; 
        y = y_in; 
        z = z_in; 
    }

    vec() {
        x = T(); 
        y = T();
        z = T();
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
        x = single; 
        y = single;
        z = single; 
        w = single; 
    }

    vec(const std::initializer_list<T> list) {
        x = list.begin()[0];
        y = list.begin()[1]; 
        z = list.begin()[2]; 
        w = list.begin()[3]; 
    }
    
    vec(const T x_in, const T y_in, const T z_in, const T w_in) {
        x = x_in; 
        y = y_in; 
        z = z_in; 
        w = w_in;
    }

    vec() {
        x = T(); 
        y = T();
        z = T(); 
        w = T(); 
    }
};


#endif