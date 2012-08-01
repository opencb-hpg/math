
#include "anova.h"

/* **************************************************************
 *    		Public functions implementations 		*
 * *************************************************************/

anova_result_t* anova_test(double msbg, double mswg, int dfbg, int dfwg, anova_result_t* anova_result) {
    anova_result->statistic = msbg / mswg;
    anova_result->dfbg = dfbg;
    anova_result->dfwg = dfwg;
    anova_result->p_value = gsl_ran_fdist_pdf(anova_result->statistic, dfbg, dfwg);
    anova_result->p_value = 1 - gsl_cdf_fdist_P(anova_result->statistic, dfbg, dfwg);
    
    return anova_result;
}
