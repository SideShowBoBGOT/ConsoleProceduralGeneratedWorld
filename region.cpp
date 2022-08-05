#include "region.h"
region::region() {};
region::region(std::vector<std::shared_ptr<circle>> planets,
    std::pair<int, int> reg) :reg{ std::move(reg) }, planets{ std::move(planets) }{};
std::pair<int, int>& region::get_reg() { return reg; }
std::vector<std::shared_ptr<circle>>& region::get_planets() { return planets; }