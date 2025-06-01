#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include"pointops.h"


void testPointOpsAddVectors() {
    std::vector<double> a = { 1, 2 };
    std::vector<double> b = { 3, 4 };
    std::vector<double> expected = { 4, 6 };
    //std::vector<double> z = PointOps::add(a, b);
    assert(PointOps::add(a, b) == expected);
}

void testPointOpsSubtractVectors() {
    std::vector<double> a = { 5, 6 };
    std::vector<double> b = { 1, 2 };
    std::vector<double> expected = { 4, 4 };
    assert(expected == PointOps::sub(a, b));
}

void testPointOpsScaleVector() {
    std::vector<double> a = { 1, 2 };
    double scalar = 3;
    std::vector<double> expected = { 3, 6 };
    assert(expected == (PointOps::scale(a, scalar)));
}

void testPointOpsAveragePoints() {
    std::vector<std::vector<double>> points = { {1, 2}, {3, 4}, {5, 6} };
    std::vector<double> expected = { 3, 4 };
    assert(PointOps::avg(points) == expected);
}
