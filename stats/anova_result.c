
#include <stdlib.h>
#include <string.h>

#include "anova_result.h"

/* **************************************************************
 *    		Public functions implementations 		*
 * *************************************************************/

anova_result_t** anova_results_new(int num_rows) {
    anova_result_t** anova_results = (anova_result_t**) calloc(num_rows, sizeof(anova_result_t*));
    
    for (int i = 0; i < num_rows; i++) {
        anova_results[i] = (anova_result_t*) calloc(1, sizeof(anova_result_t));
    }
    
    return anova_results;
}

void anova_results_free(int num_rows, anova_result_t** anova_results) {
    if (anova_results == NULL) {
        return;
    }
    
    for (int i = 0; i < num_rows; i++) {
        free(anova_results[i]);
    }    
    
    free(anova_results);
}

double* anova_results_get_statistics(int num_rows, anova_result_t** anova_results, double* statistics) {
    for (int i = 0; i < num_rows; i++) {
        statistics[i] = anova_results[i]->statistic;
    }
    
    return statistics;    
}

double* anova_results_get_p_values(int num_rows, anova_result_t** anova_results, double* p_values) {
    for (int i = 0; i < num_rows; i++) {
        p_values[i] = anova_results[i]->p_value;
    }
    
    return p_values;
}