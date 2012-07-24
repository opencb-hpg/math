
#include "statistics.h"

/* **************************************************************
 *    		Public functions implementations 		*
 * *************************************************************/

double stats_mean(const vector_t *v) {
    return gsl_stats_mean(v->values, 1, v->length);
}

double stats_variance(const vector_t *v) {
    return gsl_stats_variance(v->values, 1, v->length);
}