#ifndef ROSENBROCK_FUNC_H
#define ROSENBROCK_FUNC_H
#include<vector>
// Функция Розенброка: f(x, y) = (1 - x)^2 + 100*(y - x^2)^2
double rosenbrock(const std::vector<double>& x);
#endif // ROSENBROCK_FUNC_H
