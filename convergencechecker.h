#pragma once
#include <vector>

class ConvergenceChecker {
public:
    static bool isConverged(const std::vector<double>& values, double tol);
};
