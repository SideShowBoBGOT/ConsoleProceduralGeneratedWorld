#pragma once
#include "shape.h"
class rectangle : public shape {
protected:
    int width;
    int height;
public:
    rectangle() : shape() {
        width = 0;
        height = 0;
    }
    rectangle(int x, int y, int width, int height, shape_color color) :shape(x, y, color) {
        this->width = width;
        this->height = height;
    }
    virtual int get_width() {
        return width;
    }
    virtual int get_height() {
        return height;
    }
    virtual void set_width(int width) {
        this->width = width;
    }
    virtual void set_height(int height) {
        this->height = height;
    }
};

