#ifndef LS_FIT_H
#define LS_FIT_H

#include <sys/types.h>

#include <gsl/gsl_fit.h>

#include "vector.h"

int linear_regression(vector_t *x, vector_t *y, double *c0, double *c1, double *cov00, double *cov01, double *cov11, double *sumsq);


#endif