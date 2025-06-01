#pragma once


#include <vector>
#include <functional>


struct NMResult {
    std::vector<double> minimum; //найденная точка минимума
    double value; //значение функции в этой точке
    int iterations;
};

class NelderMead {
public:
    NelderMead(double tol = 1e-6, int max_iter = 500); //tol - tolerance (точность), max_iter - макс кол-во итераций. Значения по умолчанию.
    NMResult optimize(const std::function<double(const std::vector<double>&)>& func, const std::vector<double>& start,
                      const std::function<void( const std::vector<std::vector<double>>&)> callback = [](const std::vector<std::vector<double>>& z){} );

private:
    double tol_;
    int max_iter_;
};
