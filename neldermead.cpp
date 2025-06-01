#include "neldermead.h"
#include "pointops.h"
#include "simplexmanager.h"
#include "convergencechecker.h"

NelderMead::NelderMead(double tol, int max_iter) : tol_(tol), max_iter_(max_iter){}

NMResult NelderMead::optimize(const std::function<double(const std::vector<double>&)>& func,
                             const std::vector<double>& start,
                              const std::function<void(const std::vector<std::vector<double>>&)> callback){
    const double alpha = 1.0;
    const double beta = 2.0;
    const double gamma = 0.5;

    auto simplex = SimplexManager::initialize(start);

    const int bad_point= start.size();

    std::vector<double> func_values(simplex.size());

    for (int numPoint = 0; numPoint < simplex.size(); numPoint++) {
        func_values[numPoint] = func(simplex[numPoint]);
    }

    int iter = 0;

    while (iter < max_iter_) {
        SimplexManager::sortSimplex(simplex, func_values);

        auto centroid = SimplexManager::centroid(simplex, bad_point); //середина остальных точек (без наихудшей)
        auto x_reflective = PointOps::add(centroid, PointOps::scale(PointOps::sub(centroid, simplex[bad_point]), alpha)); //получаем отраженную точку
        double func_reflective = func(x_reflective);
        if (func_reflective < func_values[0]) { //сравниваем с лучшей

            auto x_extended = PointOps::add(centroid, PointOps::scale(PointOps::sub(x_reflective, centroid), gamma)); //расширение
            double func_extended = func(x_extended);

            if (func_extended < func_reflective) {
                simplex[bad_point] = x_extended;
            }
            else {
                simplex[bad_point] = x_reflective;
            }
        }
        else if (func_reflective < func_values[bad_point - 1]) { // провер€ем, может точка лучше хот€ бы одной
            simplex[bad_point] = x_reflective;

        }
        else { //отражение не дало улучшени€
            std::vector<double> x_contraction;
            if (func_reflective < func_values[bad_point]) { //если лучше худшей - сжимаем в сторону отраженной
                x_contraction = PointOps::add(centroid, PointOps::scale(PointOps::sub(x_reflective, centroid), gamma));
            }
            else { //отражение дало худший результат - ст€гиваем симплекс ближе к центру
                x_contraction = PointOps::add(centroid, PointOps::scale(PointOps::sub(simplex[bad_point], centroid), gamma));
            }

            double func_contraction = func(x_contraction);

            if (func_contraction < func_values[bad_point]) { //провер€ем сжатую точку
                simplex[bad_point] = x_contraction;
            }
            else { //функци€ в этой точке непредсказуема - сжимаем весь симплекс к лучшей точке
                for (int i = 1; i <= bad_point; ++i)
                    simplex[i] = PointOps::add(simplex[0], PointOps::scale(PointOps::sub(simplex[i], simplex[0]), gamma));
            }
        }
        callback(simplex);
        for (int i = 0; i <= start.size(); ++i) {
            func_values[i] = func(simplex[i]);
        }

        if (ConvergenceChecker::isConverged(func_values, tol_)) //критерий
            break;

        iter++;

    }


    return NMResult{ simplex[0],func_values[0], iter };

}
