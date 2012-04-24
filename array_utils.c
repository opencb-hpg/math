#include "array_utils.h"

int array_scalar_multiply(double *data, size_t n, double value) {
    if(data == NULL) { return -1; }
    if(n == 0) { return -2; }
    
    for(size_t i = 0; i < n; i++) {
        data[i] = data[i] * value;
    }
    return 0;
}

int array_scalar_sum(double *data, size_t n, double value) {
    if(data == NULL) { return -1; }
    if(n == 0) { return -2; }
    
    for(size_t i = 0; i < n; i++) {
        data[i] = data[i] + value;
    }
    return 0;
}


int array_sum(double *data1, const double *data2, size_t n) {
    if(data1 == NULL) { return -1; }
    if(data2 == NULL) { return -2; }
    if(n == 0) { return -3; }
    
    for(size_t i = 0; i < n; i++) {
        data1[i] = data1[i] + data2[i];
    }
    return 0;
}

int array_substract(double *data1, const double *data2, size_t n) {
    if(data1 == NULL) { return -1; }
    if(data2 == NULL) { return -2; }
    if(n == 0) { return -3; }
    
    for(size_t i = 0; i < n; i++) {
        data1[i] = data1[i] - data2[i];
    }
    return 0;
}

int array_dotproduct(double* data1, const double* data2, size_t n, double *res) {
    if(data1 == NULL) { return -1; }
    if(data2 == NULL) { return -2; }
    if(n == 0) { return -3; }
    if(res == NULL) { return -4; }
    
    *res = 0.0;
    for(size_t i = 0; i < n; i++) {
        *res += data1[i] * data2[i];
    }
    return 0;
}


int array_log(double *values, size_t n) {
    if(values == NULL) { return -1; }
    if(n == 0) { return -2; }
    
    for(size_t i = 0; i < n; i++) {
        values[i] = log(values[i]);
    }
    return 0;
}

int array_log10(double *values, size_t n) {
    if(values == NULL) { return -1; }
    if(n == 0) { return -2; }
    
    for(size_t i = 0; i < n; i++) {
        values[i] = log10(values[i]);
    }
    return 0;
}

int array_log_base(double *values, size_t n, double base) {
    if(values == NULL) { return -1; }
    if(n == 0) { return -2; }
    
    double d;
    for(size_t i = 0; i < n; i++) {
        d = log_base(values[i], base);
        if(d == -0.0) { d = 0.0; }
        values[i] = d;
    }
    return 0;
}


int array_accum(const double *values, size_t n, double *res) {
    int code = array_accum_range(values, 0, n, res);
    return (code == -4) ? -3 : code;
}

int array_accum_range(const double *values, size_t begin, size_t end, double *res) {
    if(values == NULL) { return -1; }
    if(end <= begin) { return -2; }
    if(res == NULL) { return -4; }
    
    *res = 0.0;
    for (size_t i = begin; i < end; i++) {
        if(!isnan(values[i])) {
            *res += values[i];
        }
    }
    return 0;
}
