
#ifndef TTEST_RESULT_H
#define TTEST_RESULT_H

/* **************************************
 *    		Structures  		*
 * *************************************/

/**
* @brief Structure for storing t test results
*
* Structure for storing t test results
*/
typedef struct ttest_result {
    double statistic;   	/**< Statistic of the distribution. */
    double degrees_of_freedom;  /**< Degrees of freedom. */
    double p_value;		/**< p value. */
} ttest_result_t;

/* **************************************
 *    		Functions  		*
 * *************************************/

/**
*  @brief Creates a ttest_result array
*  @param num_rows number of rows (number of features)
*  @return ttest_result array
*  
*  Creates and returns a ttest_result array
*/
ttest_result_t** ttest_results_new(int num_rows);

/**
*  @brief Frees a given ttest_result array
*  @param num_rows number of rows (number of features)
*  @param[in,out] ttest_results pointer to ttest_result array
*  @return void
*  
*  Frees a given ttest_result array
*/
void ttest_results_free(int num_rows, ttest_result_t** ttest_results);

/**
*  @brief Gets a double statistics vector from a collection of ttest_result
*  @param num_rows number of rows (number of features)
*  @param anova_results pointer to ttest_result array
*  @param[in,out] statistics pointer to the statistics vector
*  @return void
*  
*  Gets a double statistics vector from a collection of ttest_result
*/
double* ttest_results_get_statistics(int num_rows, ttest_result_t** ttest_results, double* statistics);

/**
*  @brief Gets a double p_values vector from a collection of ttest_result
*  @param num_rows number of rows (number of features)
*  @param ttest_results pointer to ttest_result array
*  @param[in,out] p_values pointer to the p_values vector
*  @return void
*  
*  Gets a double p_values vector from a collection of ttest_result
*/
double* ttest_results_get_p_values(int num_rows, ttest_result_t** ttest_results, double* p_values);

#endif /* TTEST_RESULT_H */
