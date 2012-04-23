#include "tests.h"

int linear_regression(vector_t *x, vector_t *y, double *c0, double *c1, double *cov00, double *cov01, double *cov11, double *sumsq) {
    return gsl_fit_linear(vector_get_data(x), vector_get_stride(x), vector_get_data(y), vector_get_stride(y), vector_get_size(x), c0, c1, cov00, cov01, cov11, sumsq);
}
