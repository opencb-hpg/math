
#include "p_adjust.h"


// double *FDRCorrection(double *adj_pvalues, const double *pvalues, size_t n) {
//     
// }

double *bonferroni_correction(double *adj_pvalues, const double *pvalues, size_t n) {
    size_t i;
    for(i=0; i < n; i++) {
        adj_pvalues[i] = pvalues[i] * n;
    }
//     pmin(const double *data, size_t n, double min, double *res)
    double * arr = (double *)malloc(n*sizeof(double));
    pmin(adj_pvalues, n, 1, arr);
    return arr;
}

/*
double *BHCorrection(double *adj_pvalues, const double *pvalues, size_t n) {
    int *o = ArrayUtils.order(pvalues, true);
    int *ro = ArrayUtils.order(o);

//     double[] mult = ArrayUtils.ordered(pvalues, o);
    double *mult = (double *)malloc(n*sizeof(double));
    ordered(mult, pvalues, n, o);

    size_t i;
    for(i = mult.length,j=0; i > 0; i--,j++) {
        mult[j] *= ((double)mult.length/(i));
    }
    
    return ArrayUtils.ordered(RUtils.pmin(1, RUtils.cummin(mult)), ro);
}
*/