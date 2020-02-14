# MMath
MMath is a Work-In-Progress, intended to be a light-weight header for mathematics operations used (primarily) in graphics programming. Basically, MMath is my own mini [GLM](https://glm.g-truc.net/0.9.9/index.html) that I'm making for learning purposes. I also intend to rigorously define affine spaces and operations and add compile-time type safety for them. My goal is to write code that can be optimized to use SIMD instructions by most compilers, without using SIMD intrinsics intermixed into my C++ (with a few exceptions that compilers don't treat nicely... looking at you, cross product!). 

For a rigorous introduction to affine spaces and associated math, check out: https://www.cis.upenn.edu/~cis610/geombchap2.pdf
I've also taken inspiration and advice in writing this library from [this wonderful blog post by Nathan Reed](http://www.reedbeta.com/blog/on-vector-math-libraries/)
