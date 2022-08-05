#pragma once
#include <memory>
#include <array>
#include <vector>
#include "circle.h"
class region {
protected:
    std::pair<int, int> reg;
    std::vector<std::shared_ptr<circle>> planets;
public:
    region();
    region(std::vector<std::shared_ptr<circle>> planets, std::pair<int, int> reg);
    std::pair<int, int>& get_reg();
    std::vector<std::shared_ptr<circle>>& get_planets();
};

