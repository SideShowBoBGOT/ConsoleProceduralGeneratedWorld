#pragma once
#include "shape.h"
class circle : public shape {
protected:
    int radius;
    virtual void calc_coors() override;
public:
    circle();
    circle(int x, int y, int radius, shape_color color);
    virtual int get_radius(void);
    virtual void set_radius(int radius);
};
