#include "vector.h"


double *vector_get_data(vector_t* v) {
    return v->_gsl_vector->data;
}

size_t vector_get_size(vector_t* v) {
    return v->_gsl_vector->size;
}

size_t vector_get_stride(vector_t* v) {
    return v->_gsl_vector->stride;
}
