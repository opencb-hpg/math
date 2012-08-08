#ifndef STATS_H
#define STATS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gsl/gsl_sort.h>
#include <gsl/gsl_statistics_double.h>

#include "log.h"

/* **************************************
 *    		Structures  		*
 * *************************************/

/**
* @brief Structure for storing t test results
*
* Structure for storing t test results
*/
typedef struct vector {
    size_t length;   	/**< Length of the vector. */
    double* values;   	/**< Values in the vector. */
} vector_t;

/* **************************************
 *    		Functions  		*
 * *************************************/

/**
*  @brief Calculates mean of values of a double vector
*  @param v pointer to the vector structure
*  @return mean value
*  
*  Calculates mean of values of a double vector
*/
double stats_mean(const vector_t *v);

/**
*  @brief Calculates variance of values of a double vector
*  @param v pointer to the vector structure
*  @return variance value
*  
*  Calculates variance of values of a double vector
*/
double stats_variance(const vector_t *v);

/**
*  @brief Calculates median of a double vector
*  @param v pointer to the vector structure
*  @return median value
*  
*  Calculates median of a double vector
*/
double stats_median(vector_t *v);

/**
*  @brief Calculates median of a SORTED double vector
*  @param v pointer to the vector structure
*  @return median value
*  
*  Calculates median of a SORTED double vector
*/
double stats_median_sorted_vector(const vector_t *v);

/**
*  @brief Calculates percentile of a double vector
*  @param v pointer to the vector structure
*  @param percentile value of the percentile to calculate
*  @return value meeting the percentile
*  
*  Calculates percentile of a double vector
*/
double stats_percentile(vector_t *v, double percentile);

/**
*  @brief Calculates percentile of a SORTED double vector
*  @param v pointer to the vector structure
*  @param percentile value of the percentile to calculate
*  @return value meeting the percentile
*  
*  Calculates percentile of a SORTED double vector
*/
double stats_percentile_sorted_vector(const vector_t *v, double percentile);

/**
*  @brief Creates a new vector from a double pointer
*  @param values pointer to the double values
*  @param length length of the vector
*  @return created vector 
*  
*  Creates a new vector from a double pointer and its length
*/
vector_t* vector_new(double *values, size_t length);

/**
*  @brief Frees a vector
*  @param v pointer to the vector structure
*  @return void
*  
*  Frees a vector
*/
void vector_free(vector_t* v);

/**
*  @brief Sorts double values of a vector
*  @param v pointer to the vector structure
*  @param length length of the vector
*  @return sorted vector 
*  
*  Sorts double values of a vector
*/
vector_t* vector_sort(vector_t* v);


#endif  /* STATS_H */