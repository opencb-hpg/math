
#include "ttest.h"

/* **************************************************************
 *    		Public functions implementations 		*
 * *************************************************************/

double degrees_of_freedom(double var1, double var2, double n1, double n2) {
    return ( ((var1 / n1) + (var2 / n2)) * ((var1 / n1) + (var2 / n2))) /
             ((var1 * var1) / (n1 * n1 * (n1 - 1)) + (var2 * var2) /
                (n2 * n2 * (n2 - 1))); 
}

double ttest_one_sample(double mean, double mu, double var, double n) {
    return (mean - mu) / sqrt(var / n);
}

double ttest_two_samples(double mean1, double mean2, double var1, double var2, double n1, double n2) {
    return (mean1 - mean2) / sqrt((var1 / n1) + (var2 / n2));
}

ttest_result_t* ttest_two_sided_one_sample(double mean, double mu, double var, double n, ttest_result_t* ttest_result) {
    ttest_result->statistic = ttest_one_sample(mean, mu, var, n);
    ttest_result->degrees_of_freedom = n - 1;
    ttest_result->p_value = 2.0 * gsl_cdf_tdist_P((-1) * fabs(ttest_result->statistic), ttest_result->degrees_of_freedom);
 
    return ttest_result;
}

ttest_result_t* ttest_two_sided_two_samples(double mean1, double mean2, double var1, double var2, double n1, double n2, ttest_result_t* ttest_result) {
    ttest_result->statistic = ttest_two_samples(mean1, mean2, var1, var2, n1, n2);
    ttest_result->degrees_of_freedom = degrees_of_freedom(var1, var2, n1, n2);
    ttest_result->p_value = 2.0 * gsl_cdf_tdist_P((-1) * fabs(ttest_result->statistic), ttest_result->degrees_of_freedom);
    
    return ttest_result;
}

