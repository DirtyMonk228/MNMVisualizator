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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    testConvergenceCheckerHandlesZeroVariance();
    testConvergenceCheckerHandlesNonConverged();
    testConvergenceCheckerHandlesConverged();
    std::cout << "All ConvergenceChecker tests passed." << std::endl;

    testPointOpsAddVectors();
    testPointOpsSubtractVectors();
    testPointOpsScaleVector();
    testPointOpsAveragePoints();
    std::cout << "All PointOps tests passed." << std::endl;



    testSortSimplex();
    testCentroid();
    std::cout << "All SimplexManager tests passed." << std::endl;

    MNMWidget btn;
    btn.show();
    return app.exec();
}
