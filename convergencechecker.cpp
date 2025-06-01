#include "convergencechecker.h"
#include <cmath>

bool ConvergenceChecker::isConverged(const std::vector<double>& values, double tol) {
    double mean = 0;
    for (double v : values) {
        mean = mean + v;
    }

    mean = mean / values.size();

    double var = 0;

    for (double v : values) {
        var += (v - mean) * (v - mean);
    }

    var = var / values.size();

    return std::sqrt(var) < tol;
}
