#pragma once
#include <iostream>
#include "neldermead.h"
#include <cassert>
#include <vector>
#include "convergencechecker.h"
#include"simplexmanager.h"


// Test that the initialize method correctly creates a simplex
void testInitialize() {
    std::vector<double> start = { 1.0, 2.0 };
    double offset = 0.05;
    auto simplex = SimplexManager::initialize(start, offset);

    assert(simplex.size() == start.size() + 1);
    for (size_t i = 0; i < simplex.size(); ++i) {
        assert(simplex[i].size() == start.size());
        if (i < start.size()) {
            assert(simplex[i][i] == (start[i] + offset));
        }
    }
}

// Test that the sortSimplex method correctly sorts the simplex based on function values
void testSortSimplex() {
    std::vector<std::vector<double>> simplex = { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} };
    std::vector<double> f_values = { 0.5, 0.3, 0.7 };

    SimplexManager::sortSimplex(simplex, f_values);

    assert((f_values[0] <= f_values[1]) && (f_values[1] <= f_values[2]));
    //assert((simplex[0] < simplex[1]) && (simplex[1] < simplex[2])); // Assuming lexicographic order for vector comparison
}

// Test that the centroid method correctly calculates the centroid of a simplex
void testCentroid() {
    std::vector<std::vector<double>> simplex = { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} };
    int exclude = 2;
    auto centroid = SimplexManager::centroid(simplex, exclude);

    std::vector<double> expected_centroid = { 2.0, 3.0 }; // (1+3)/2, (2+4)/2

    assert(centroid == expected_centroid);
}
