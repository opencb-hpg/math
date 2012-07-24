
#include "p_adjust.h"
#include "R_utils.h"

// double *FDRCorrection(double *adj_pvalues, const double *pvalues, size_t n) {
//     
// }

int Bonferroni_correction(double *pvalues, size_t n) {
    for(size_t i=0; i < n; i++) {
        pvalues[i] = pvalues[i] * n;
    }
//     pmin(const double *data, size_t n, double min, double *res)
    double *arr = (double *)malloc(n*sizeof(double));
    pmin(pvalues, n, 1, arr);
    
    free(pvalues);
    pvalues = arr;
    return 0;
}


int BH_correction(double *pvalues, size_t n) {
    size_t *o_indices = (size_t*)malloc(n*sizeof(size_t));
    size_t *ro_indices = (size_t*)malloc(n*sizeof(size_t));

    array_order(pvalues, n, 0, o_indices);
    array_order(o_indices, n, 1, ro_indices);

    double *mult = (double *)malloc(n*sizeof(double));
    array_ordered(pvalues, n, o_indices, mult);
    
    for(size_t i = n,j=0; i > 0; i--,j++) {
        mult[j] *= ((double)n/(i));
    }
    
    double *cummin_mult = (double*)malloc(n*sizeof(double));
    double *cummin_pmin_mult = (double*)malloc(n*sizeof(double));
//     double *cummin_pmin_ordered_mult = (double*)malloc(n*sizeof(double));
    cummin(mult, n, cummin_mult);
    pmin(cummin_mult, n, 1, cummin_pmin_mult);
    array_ordered(cummin_pmin_mult, n, ro_indices, pvalues);
//     free(pvalues);
//     pvalues = cummin_pmin_ordered_mult;
    
    free(o_indices);
    free(ro_indices);
    free(mult);
    free(cummin_mult);
    free(cummin_pmin_mult);
    return 0;
}
