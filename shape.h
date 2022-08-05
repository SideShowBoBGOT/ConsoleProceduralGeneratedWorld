#pragma once
#include <vector>
enum shape_color {
    black = 7,
    dark_blue = 16,
    dark_green = 32,
    dark_aqua = 48,
    dark_red = 64,
    dark_purple = 80,
    dark_yellow = 96,
    light_grey = 112,
    grey = 128,
    blue = 144,
    green = 160,
    aqua = 176,
    red = 192,
    purple = 208,
    yellow = 224,
    white = 240,
};

class shape {
protected:
    int x;
    int y;
    shape_color color;
    std::vector<std::pair<int, int>> coors;
    virtual void calc_coors() = 0;
public:
    shape();
    shape(int x, int y, shape_color color);
    virtual int get_x();
    virtual int get_y();
    virtual void set_x(int x);
    virtual void set_y(int y);
    virtual void set_color(shape_color color);
    virtual shape_color get_color();
    virtual std::vector<std::pair<int, int>>& get_coors();
};

