#include "circle.h"
void circle::calc_coors() {
    for (int i = 0; i < radius; i++) {
        int len = static_cast<int>(ceil(sqrt(pow(radius, 2) - pow(i, 2))));
        for (int k = radius - 1, limit = 0; k >= 0 && limit < len;k--, limit++) {
            coors.push_back(std::pair<int, int>(x + k, y + radius - 1 + i));
            coors.push_back(std::pair<int, int>(x + radius * 2 - 2 - k, y + radius - 1 - i));
            coors.push_back(std::pair<int, int>(x + radius * 2 - 2 - k, y + radius - 1 + i));
            coors.push_back(std::pair<int, int>(x + k, y + radius - 1 - i));
        }
    }
}
circle::circle() : shape(), radius{ 0 } {}
circle::circle(int x, int y, int radius, shape_color color) :shape(x, y, color), radius{ radius }{
    calc_coors();
}
int circle::get_radius(void) { return radius; }
void circle::set_radius(int radius) { this->radius = radius; }