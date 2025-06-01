#pragma once
#include "pointops.h"



std::vector<double> PointOps::add(const std::vector<double>& a, const std::vector<double>& b) {
    std::vector<double> result(a.size());

    for (int i = 0; i < a.size(); i++) {
        result[i] = a[i] + b[i];
    }

    return result;
}

std::vector<double> PointOps::sub(const std::vector<double>& a, const std::vector<double>& b) {
    std::vector<double> result(a.size());

    for (int i = 0; i < a.size(); i++) {
        result[i] = a[i] - b[i];
    }

    return result;
}

std::vector<double> PointOps::scale(const std::vector<double>& a, double scalar) {
    std::vector<double> result(a.size());
    for (int i = 0; i < a.size(); i++) {
        result[i] = a[i] * scalar;
    }

    return result;
}

std::vector<double> PointOps::avg(const std::vector<std::vector<double>>& points) {
    std::vector<double> result(points[0].size(), 0.0);

    for (auto& p : points) {
        for (int i = 0; i < p.size(); i++) {
            result[i] += p[i];
        }
    }
    for (double &val : result) {
        val = val / points.size();
    }

    return result;
}
