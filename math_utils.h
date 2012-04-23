#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <math.h>

inline double log_base(double value, double base) {
    return log(value) / log(base);
}

inline double round_digits(double a, double exp) {
    return round(a * pow(10, exp)) / pow(10, exp);
}

#endif
