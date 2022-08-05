#include "shape.h"
shape::shape() : x{ 0 }, y{ 0 }, color{ shape_color::black }{}
shape::shape(int x, int y, shape_color color) : x{ x }, y{ y }, color{ color } {}
int shape::get_x() {
    return x;
}
int shape::get_y() {
    return y;
}
void shape::set_y(int y) {
    this->y = y;
}
void shape::set_x(int x) {
    this->x = x;
}
void shape::set_color(shape_color color) {
    this->color = color;
}
shape_color shape::get_color() {
    return color;
}
std::vector<std::pair<int, int>>& shape::get_coors() {
    return coors;
};
