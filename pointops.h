#pragma once
#include <vector>

class PointOps { //âåêòîðíûå îïåðàöèè
public:
    static std::vector<double> add(const std::vector<double>& a, const std::vector<double>& b);  //ñêëàäûâàåò âåêòîðà ïîýëåìåíòíî
    static std::vector<double> sub(const std::vector<double>& a, const std::vector<double>& b); //âû÷èòàåò èç âåêòîðà à âåêòîð á
    static std::vector<double> scale(const std::vector<double>& a, double scalar); //óìíîæåíèå âåêòîðà íà ñêàëÿð
    static std::vector<double> avg(const std::vector<std::vector<double>>& points); //ñðåäíÿÿ òî÷êà èç íàáîðà òî÷åê
};
