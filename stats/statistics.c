
#include "statistics.h"

/* **************************************************************
 *    		Public functions implementations 		*
 * *************************************************************/

/* **********************************************
 *    		Statistic functions  		*
 * *********************************************/

double stats_mean(const vector_t *v) {
    return gsl_stats_mean(v->values, 1, v->length);
}

double stats_variance(const vector_t *v) {
    return gsl_stats_variance(v->values, 1, v->length);
}

double stats_median(vector_t *v) {
    return stats_median_sorted_vector(vector_sort(v));
}

double stats_median_sorted_vector(const vector_t *v) {
    return gsl_stats_median_from_sorted_data(v->values, 1, v->length);
}

double stats_percentile(vector_t *v, double percentile) {
    return stats_percentile_sorted_vector(vector_sort(v), percentile);
}

double stats_percentile_sorted_vector(const vector_t *v, double percentile) {
    if ((percentile > 100) || (percentile < 0)) {
        LOG_FATAL("Percentile value must be between 0 and 100");
    }
      
    return gsl_stats_quantile_from_sorted_data(v->values, 1, v->length, (percentile / 100));  
}

/* **********************************************
 *    		Vector functions  		*
 * *********************************************/

vector_t* vector_new(double *values, size_t length) {
    vector_t* vector_p = (vector_t*) calloc(1, sizeof(vector_t));
    
    vector_p->length = length;
    vector_p->values = (double*) calloc(length, sizeof(double));
    memcpy(vector_p->values, values, length * sizeof(double));
    
    return vector_p;
}

void vector_free(vector_t* v) {
    if (v == NULL) {
        return;
    }
    
    if (v->values != NULL) {
        free(v->values);
    }    
    free(v);
    
    return;
}

vector_t* vector_sort(vector_t* v) {
    gsl_sort(v->values, 1, v->length);
    return v;    
}