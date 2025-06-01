#pragma once

#include <vector>
#include <functional>
class SimplexManager {
public:
    static std::vector<std::vector<double>> initialize(const std::vector<double>& start, double offset = 0.05);
    static void sortSimplex(std::vector<std::vector<double>>& simplex, std::vector<double>& f_values);

    static std::vector<double> centroid(const std::vector<std::vector<double>>& simplex, int exclude);
};
