#ifndef VECTOR_H
#define VECTOR_H

typdef vector {
  gsl_vector _gsl_vector;
} vector_t;


vector_t* vector_new(double *data, size_t n);

vector_t* vector_init(double *data, size_t n, vector_t *dest);

vector_t* vector_alloc(size_t n);
 
void vector_free(vector_t *v);


double vector_get(size_t i, vector_t*);

void vector_set(size_t i, double x, vector_t *v);

void vector_set_all (double x, vector_t *v);


int vector_printf (const vector_t * v, const char * format);

int vector_fprintf (const vector_t * v, const char * format, FILE * stream);


int vector_memcpy (const vector_t *src, vector_t *dest);


#endif