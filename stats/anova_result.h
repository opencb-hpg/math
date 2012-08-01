
#ifndef ANOVA_RESULT_H
#define ANOVA_RESULT_H

/* **************************************
 *    		Structures  		*
 * *************************************/

/**
* @brief Structure for storing anova results
*
* Structure for storing anova results
*/
typedef struct anova_result {
    double statistic;   	/**< Statistic of the distribution. */
    int dfbg; 			/**< Degrees of freedom in numerator (between groups). */
    int dfwg; 			/**< Degrees of freedom in denominator (within groups). */
    double p_value;		/**< p value. */
} anova_result_t;

/* **************************************
 *    		Functions  		*
 * *************************************/

/**
*  @brief Creates a anova_result array
*  @param num_rows number of rows (number of features)
*  @return anova_result array
*  
*  Creates and returns an anova_result array
*/
anova_result_t** anova_results_new(int num_rows);

/**
*  @brief Frees a given anova_result array
*  @param[in,out] anova_results pointer to anova_result array
*  @return void
*  
*  Frees a given anova_result array
*/
void anova_results_free(int num_rows, anova_result_t** anova_results);

/**
*  @brief Gets a double statistics vector from a collection of anova_result
*  @param num_rows number of rows (number of features)
*  @param anova_results pointer to anova_result array
*  @param[in,out] statistics pointer to the statistics vector
*  @return void
*  
*  Gets a double statistics vector from a collection of anova_result
*/
double* anova_results_get_statistics(int num_rows, anova_result_t** anova_results, double* statistics);

/**
*  @brief Gets a double p_values vector from a collection of anova_result
*  @param num_rows number of rows (number of features)
*  @param anova_results pointer to anova_result array
*  @param[in,out] p_values pointer to the p_values vector
*  @return void
*  
*  Gets a double p_values vector from a collection of anova_result
*/
double* anova_results_get_p_values(int num_rows, anova_result_t** anova_results, double* p_values);

#endif /* ANOVA_RESULT_H */