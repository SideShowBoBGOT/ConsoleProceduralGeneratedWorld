#include "camera.h"
void camera::update_coors() {
    int last_x = get_updated_coor(x + get_width());
    int last_y = get_updated_coor(y + get_height());
    int index = 0;
    if (x < last_x && y < last_y)
        for (int i = y; i < last_y; i++)
            for (int j = x; j < last_x; j++, index++)
                coors[index] = std::pair<int, int>(j, i);
    else if (x >= last_x && y < last_y) {
        for (int i = y; i < last_y; i++) {
            for (int j = x; j < map_size * region_size; j++, index++)
                coors[index] = std::pair<int, int>(j, i);
            for (int j = 0; j < last_x; j++, index++)
                coors[index] = std::pair<int, int>(j, i);
        }
    }
    else if (x < last_x && y >= last_y) {
        for (int i = y; i < map_size * region_size; i++)
            for (int j = x; j < last_x; j++, index++)
                coors[index] = std::pair<int, int>(j, i);
        for (int i = 0; i < last_y; i++)
            for (int j = x; j < last_x; j++, index++)
                coors[index] = std::pair<int, int>(j, i);
    }
    else if (x >= last_x && y >= last_y) {
        for (int i = y; i < map_size * region_size; i++) {
            for (int j = x; j < map_size * region_size; j++, index++)
                coors[index] = std::pair<int, int>(j, i);
            for (int j = 0; j < last_x; j++, index++)
                coors[index] = std::pair<int, int>(j, i);
        }
        for (int i = 0; i < last_y; i++) {
            for (int j = x; j < map_size * region_size; j++, index++)
                coors[index] = std::pair<int, int>(j, i);
            for (int j = 0; j < last_x; j++, index++)
                coors[index] = std::pair<int, int>(j, i);
        }
    }
}
void camera::update_visible_regions() {
    int reg_x = x / region_size, reg_y = y / region_size;
    int last_reg_x = get_updated_coor(x + width) / region_size;
    int last_reg_y = get_updated_coor(y + height) / region_size;
    visible_regions[0] = std::pair<int, int>(reg_x, reg_y);
    visible_regions[1] = std::pair<int, int>(last_reg_x, reg_y);
    visible_regions[2] = std::pair<int, int>(reg_x, last_reg_y);
    visible_regions[3] = std::pair<int, int>(last_reg_x, last_reg_y);
}
camera::camera() {}
camera::camera(int map_size, int region_size, int width, int height) :map_size{ map_size },
region_size{ region_size }, width{ width }, height{ height }, x{ 0 }, y{ 0 },
visible_regions{ std::vector<std::pair<int, int>>(4) },
coors{ std::vector<std::pair<int, int>>(width * height) } {
    update_visible_regions();
    update_coors();
}
int camera::get_updated_coor(int coor) {
    if (coor < 0)
        coor += map_size * region_size;
    if (coor >= map_size * region_size)
        coor -= map_size * region_size;
    return coor;
}
void camera::input() {
    char key = _getch();
    switch (key)
    {
    case 'w': case 'W':
        y--;
        break;
    case 's': case 'S':
        y++;
        break;
    case 'a': case 'A':
        x--;
        break;
    case 'd': case 'D':
        x++;
        break;
    default:
        break;
    }
    y = get_updated_coor(y);
    x = get_updated_coor(x);
    update_visible_regions();
    update_coors();
}
int camera::get_width() {
    return width;
}
int camera::get_height() {
    return height;
}
int camera::get_x() {
    return x;
}
int camera::get_y() {
    return y;
}
std::vector<std::pair<int, int>>& camera::get_visible_regions() { return visible_regions; }
std::vector<std::pair<int, int>>& camera::get_coors() { return coors; }