#ifndef MY_MATH_DEFINED
    #define MY_MATH_DEFINED

    // Mathematical constants
    #define PI 3.14159265359 // pi
    #define EULERS_CONSTANT 2.71828 // e
    #define PYTHAGORAS_CONSTANT 1.41421 // sqrt(2)

    // Inplace math macros
    #define ADD_INPLACE(v1, v2) (v1 + v2)
    #define SUB_INPLACE(v1, v2) (v1 - v2)
    #define MUL_INPLACE(v1, v2) (v1 * v2)
    #define DIV_INPLACE(v1, v2) (v1 / v2)
    #define MOD_INPLACE(v1, v2) (v1 % v2)

    // Counting functions
    void resetCounter();
    int incrementCounter();
    int decrementCounter();
    int getCounter();
    void setCounter(int newCount);

    int add(int v1, int v2);
    int subtract(int v1, int v2);
    int multiply(int v1, int v2);
    int divide(int v1, int v2);
    int modulus(int v1, int v2);

#endif // MY_MATH_DEFINED
