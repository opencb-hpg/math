
#include "correlation.h"

/* **************************************************************
 *    		Public functions implementations 		*
 * *************************************************************/

double correlation(double* values1, double* values2, double size) {
    return gsl_stats_correlation(values1, 1, values2, 1, size);
}
