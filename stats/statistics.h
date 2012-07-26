#ifndef STATS_H
#define STATS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gsl/gsl_statistics_double.h>

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

#endif  /* STATS_H */