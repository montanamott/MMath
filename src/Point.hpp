#ifndef POINT_CLASS
#define POINT_CLASS

#include <iostream> 


// A point is an element of some n-dimensional Euclidean space. In most cases, the point will have an implcit frame of the origin 
// <0, ..., 0> along with the standard basis vectors e_1, ..., e_n. However, my library imposes no such restrictions. The main reason
// we introduce the concepts of points and affine spaces as a whole is so the compiler can enforce types with affine operations 
// for example, a point subtracted from a point gives a vector, not another point. In many graphics math libraries, vectors are used for 
// everything and such distinctions are left up to the user. 

// Note: As with the vector class, initializer list constructor is not the most efficient, so I suggest using it mainly for convenience/debugging purposes. 
//       For 2-3 dim points, use the multi-element constructor instead. 

// Generic N-dimensional point
template <typename T, int N> 
struct point {
    T data[N];

    explicit point(const T single) {
        for(unsigned i = 0; i < N; ++i) 
        { data[i] = single; }
    }

    point(const std::initializer_list<T> list) {
        for(unsigned i = 0; i < N; ++i) 
        { data[i] = list.begin()[i]; }
    }

    point() {
        for(unsigned i = 0; i < N; ++i) 
        { data[i] = T(); }
    }
};

// Specialized, 2 component point
template <typename T> struct point<T, 2> {
    union {
        T data[2]; 
        struct {T x, y; }; 
    };

    explicit point(const T single) {
        x = single; 
        y = single;
    }

    point(const std::initializer_list<T> list) {
        x = list.begin()[0];
        y = list.begin()[1]; 
    }

    point(const T x_in, const T y_in) {
        x = x_in; 
        y = y_in; 
    }

    point() {
        x = T(); 
        y = T();
    }
};

// Specialized, 3 component point
template <typename T> struct point<T, 3> {
    union {
        T data[3]; 
        struct {T x, y, z; }; 
        struct {T r, g, b; };
    };

    explicit point(const T single) {
        x = single; 
        y = single;
        z = single;
    }

    point(const std::initializer_list<T> list) {
        x = list.begin()[0];
        y = list.begin()[1]; 
        z = list.begin()[2];
    }

    point(const T x_in, const T y_in, const T z_in) {
        x = x_in; 
        y = y_in; 
        z = z_in; 
    }

    point() {
        x = T(); 
        y = T();
        z = T();
    }
};

#endif