#include "array_utils.h"

double *scalar_multiply(double *data, size_t n, double value) {
    if(data == NULL || n < 1) { return NULL; }
    
    for(size_t i = 0; i < n; i++) {
        data[i] = data[i] * value;
    }
    return data;
}

double *scalar_sum(double *data, size_t n, double value) {
    if(data == NULL || n < 1) { return NULL; }
    
    for(size_t i = 0; i < n; i++) {
        data[i] = data[i] + value;
    }
    return data;
}


double *array_sum(double *data1, double *data2, size_t n) {
    if(data1 == NULL || data2 == NULL || n < 1) { return NULL; }
    
    for(size_t i = 0; i < n; i++) {
        data1[i] = data1[i] + data2[i];
    }
    return data1;
}

double *array_substract(double *data1, double *data2, size_t n) {
    if(data1 == NULL || data2 == NULL || n < 1) { return NULL; }
    
    for(size_t i = 0; i < n; i++) {
        data1[i] = data1[i] - data2[i];
    }
    return data1;
}

double array_dotproduct(double* data1, double* data2, size_t n) {
    if(data1 == NULL || data2 == NULL || n < 1) { return NAN; }
    
    double dot_product = 0.0;
    for(size_t i = 0; i < n; i++) {
        dot_product += data1[i] * data2[i];
    }
    return dot_product;
}


double *array_log(double *values, size_t n) {
    if(values == NULL || n < 1) { return NULL; }
    
    for(size_t i = 0; i < n; i++) {
        values[i] = log(values[i]);
    }
    return values;
}

double *array_log10(double *values, size_t n) {
    if(values == NULL || n < 1) { return NULL; }
    
    for(size_t i = 0; i < n; i++) {
        values[i] = log10(values[i]);
    }
    return values;
}

double *array_log_base(double *values, size_t n, double base) {
    if(values == NULL || n < 1) { return NULL; }
    
    double d;
    for(size_t i = 0; i < n; i++) {
        d = log_base(values[i], base);
        if(d == -0.0) { d = 0.0; }
        values[i] = d;
    }
    return values;
}


double array_accum(const double *values, size_t n) {
    return array_accum_range(values, 0, n);
}

double array_accum_range(const double *values, size_t begin, size_t end) {
    if(values == NULL || end < begin) { return NAN; }
    
    double sum = 0.0;
    for (size_t i = begin; i < end; i++) {
        if(!isnan(values[i])) {
            sum += values[i];
        }
    }
    return sum;
}
