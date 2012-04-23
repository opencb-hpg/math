#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <math.h>
#include <stdlib.h>

#include "math_utils.h"

double *scalar_multiply(double *data, size_t n, double value);

double *scalar_sum(double *data, size_t n, double value);


double *array_sum(double *data1, double *data2, size_t n);

double *array_substract(double *data1, double *data2, size_t n);

double array_dotproduct(double *data1, double *data2, size_t n);


double *array_log(double *values, size_t n);

double *array_log10(double *values, size_t n);

double *array_log_base(double *values, size_t n, double base);


double array_accum(const double *values, size_t n);

double array_accum_range(const double *values, size_t begin, size_t end);


#endif
