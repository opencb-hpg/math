
#ifndef ANOVA_H
#define ANOVA_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gsl/gsl_randist.h>

#include "anova_result.h"

/* **************************************
 *    		Structures  		*
 * *************************************/

/* **************************************
 *    		Functions  		*
 * *************************************/

/**
*  @brief Computes anova
*  @param msbg mean square (between groups)
*  @param mswg mean square (within groups)
*  @param dfbg degrees of freedom in numerator (between groups)
*  @param dfwg degrees of freedom in denominator (within groups)
*  @param anova_results pointer to anova results structure
*  @return pointer to anova result structure (statistic, degrees of freedom [dfbg and dfwg] and p-value)
*  
*  Computes anova.
*/
anova_result_t* anova_test(double msbg, double mswg, int dfbg, int dfwg, anova_result_t* anova_result);

#endif /* ANOVA_H */
