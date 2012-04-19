#ifndef MATRIX_H
#define MATRIX_H

typdef matrix {
  gsl_matrix _gsl_matrix;
} matrix_t;


matrix_t* matrix_new(double *data, size_t n);

matrix_t* matrix_init(double *data, size_t n, matrix_t *dest);

matrix_t* matrix_alloc(size_t n);
 
void matrix_free(matrix_t *v);


double matrix_get(size_t i, size_t j, matrix_t* m);

void matrix_set(size_t i, size_t j, double x, matrix_t *m);

void matrix_set_all (double x, matrix_t *v);


int matrix_printf (const matrix_t * m, const char * format);

int matrix_fprintf (const matrix_t * m, const char * format, FILE * stream);


int matrix_memcpy (const matrix_t *src, matrix_t *dest);


int matrix_get_row (vector_t *v, const matrix_t * m, size_t i);

int matrix_get_col (vector_t *v, const matrix_t * m, size_t j);

int matrix_set_row (size_t i, const vector_t * v, matrix_t *m);

int matrix_set_col (size_t j, const vector_t * v, matrix_t *m);


#endif