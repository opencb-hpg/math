
#ifndef TTEST_H
#define TTEST_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gsl/gsl_randist.h>
#include <gsl/gsl_cdf.h>

#include "ttest_result.h"

#define P_VALUE_THRESHOLD	0.05

/* **************************************
 *    		Structures  		*
 * *************************************/

/* **************************************
 *    		Functions  		*
 * *************************************/

/**
*  @brief Computes approximate degrees of freedom for 2-sample t-test
*  @param var1 first sample variance
*  @param var2 second sample variance
*  @param n1 first sample n
*  @param n2 second sample n
*  @return approximate degrees of freedom
*  
*  Computes approximate degrees of freedom for 2-sample t-test
*/
double degrees_of_freedom(double var1, double var2, double n1, double n2);

/**
*  @brief Computes t test statistic for 1-sample t-test
*  @param mean sample mean
*  @param mu constant to test again
*  @param var sample variance
*  @param n sample n
*  @return t test statistic
*  
*  Computes t test statistic for 1-sample t-test
*/
double ttest_one_sample(double mean, double mu, double var, double n);

/**
*  @brief Computes p-value for 2-sample t-test
*  @param mean1 first sample mean
*  @param mean2 second sample mean
*  @param var1 first sample variance
*  @param var2 second sample variance
*  @param n1 first sample n
*  @param n2 second sample n
*  @return t test statistic
*  
*  Computes p-value for 2-sided, 2-sample t-test.
*/
double ttest_two_samples(double mean1, double mean2, double var1, double var2, double n1, double n2);

/**
*  @brief Computes p-value for 2-sided, 1-sample t-test
*  @param mean sample mean
*  @param mu constant to test again
*  @param var sample variance
*  @param n sample n
*  @param ttest_results pointer to t test results structures
*  @return pointer to t test result structure (statistic, degrees of freedom and p-value)
*  
*  Computes p-value for 2-sided, 1-sample t-test
*/
ttest_result_t* ttest_two_sided_one_sample(double mean, double mu, double var, double n, ttest_result_t* ttest_result);

/**
*  @brief Computes p-value for 2-sided, 2-sample t-test
*  @param mean1 first sample mean
*  @param mean2 second sample mean
*  @param var1 first sample variance
*  @param var2 second sample variance
*  @param n1 first sample n
*  @param n2 second sample n
*  @param ttest_results pointer to t test results structures
*  @return pointer to t test result structure (statistic, degrees of freedom and p-value)
*  
*  Computes p-value for 2-sided, 2-sample t-test.
*/
ttest_result_t* ttest_two_sided_two_samples(double mean1, double mean2, double var1, double var2, double n1, double n2, ttest_result_t* ttest_result);

#endif /* TTEST_H */
