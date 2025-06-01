#include "rosenbrock_func.h"

// Функция Розенброка: f(x, y) = (1 - x)^2 + 100*(y - x^2)^2
double rosenbrock(const std::vector<double>& x) {
    return (1 - x[0]) * (1 - x[0]) + 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]);
}
