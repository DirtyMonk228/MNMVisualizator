#pragma once
#include <iostream>
#include<QApplication>
#include "neldermead.h"
#include"mnmvisualizator.h"
#include"mnmwidget.h"
#include <cassert>
#include <vector>
#include "convergencechecker.h"
#include"convergence_checker_tests.h"
#include"point_ops_tests.h"
#include"simplex_manager_tests.h"


void testConvergenceCheckerHandlesZeroVariance() {
    std::vector<double> values = { 1, 1, 1 };
    double tol = 0.1;
    assert(ConvergenceChecker::isConverged(values, tol));
}

void testConvergenceCheckerHandlesNonConverged() {
    std::vector<double> values = { 1, 2, 3 };
    double tol = 0.1;
    assert(!ConvergenceChecker::isConverged(values, tol));
}

void testConvergenceCheckerHandlesConverged() {
    std::vector<double> values = { 1.001, 1.002, 1.003 };
    double tol = 0.01;
    assert(ConvergenceChecker::isConverged(values, tol));
}

