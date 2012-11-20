
#include <stdlib.h>
#include <string.h>

#include "ttest_result.h"

/* **************************************************************
 *    		Public functions implementations 		*
 * *************************************************************/

ttest_result_t** ttest_results_new(int num_rows) {
    ttest_result_t** ttest_results = (ttest_result_t**) calloc(num_rows, sizeof(ttest_result_t*));
    
    for (int i = 0; i < num_rows; i++) {
        ttest_results[i] = (ttest_result_t*) calloc(1, sizeof(ttest_result_t));
    }
    
    return ttest_results;
}

void ttest_results_free(int num_rows, ttest_result_t** ttest_results) {
    if (ttest_results == NULL) {
        return;
    }
    
    for (int i = 0; i < num_rows; i++) {
        free(ttest_results[i]);
    }    
    
    free(ttest_results);
}

double* ttest_results_get_statistics(int num_rows, ttest_result_t** ttest_results, double* statistics) {
    for (int i = 0; i < num_rows; i++) {
        statistics[i] = ttest_results[i]->statistic;
    }
    
    return statistics;    
}

double* ttest_results_get_p_values(int num_rows, ttest_result_t** ttest_results, double* p_values) {
    for (int i = 0; i < num_rows; i++) {
        p_values[i] = ttest_results[i]->p_value;
    }
    
    return p_values;
}
