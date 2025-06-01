#include "simplexmanager.h"
#include "pointops.h"
#include <algorithm>


std::vector<std::vector<double>> SimplexManager::initialize(const std::vector<double>& start, double offset) {

    int n = start.size();
    std::vector<std::vector<double>> simplex(n + 1, start);
    for (int i = 0; i < n; ++i)
        simplex[i + 1][i] += offset;
    return simplex;
}

void SimplexManager::sortSimplex(std::vector<std::vector<double>>& simplex, std::vector<double>& f_values) {



    for (int i = 0; i < simplex.size(); i++) {
        for (int j = 0; j < simplex.size() - 1; j++) {
            if (f_values[j] > f_values[j + 1]) {
                std::swap(f_values[j], f_values[j + 1]);
                std::swap(simplex[j], simplex[j + 1]);
            }
        }
    }
}

std::vector<double> SimplexManager::centroid(const std::vector<std::vector<double>>& simplex, int exclude) {

    std::vector<std::vector<double>> tmp = simplex;
    tmp.erase(tmp.begin() + exclude);

    return PointOps::avg(tmp);
}
