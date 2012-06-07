#include "stats_inference.h"

inline double chi_square(int observed, int expected, double* p_value) {
    double stat = ((observed - expected) * (observed - expected)) / expected;
    
    // TODO calculate p-value
    
    return stat;
}
