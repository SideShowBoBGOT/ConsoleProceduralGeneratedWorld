#pragma once
#include <vector>
#include<conio.h>
class camera {
private:
    int x;
    int y;
    int width;
    int height;
    int map_size;
    int region_size;
    std::vector<std::pair<int, int>> coors;
    std::vector<std::pair<int, int>> visible_regions;
    void update_coors();
    void update_visible_regions();
public:
    camera();
    camera(int map_size, int region_size, int width, int height);
    int get_updated_coor(int coor);
    void input();
    int get_width();
    int get_height();
    int get_x();
    int get_y();
    std::vector<std::pair<int, int>>& get_visible_regions();
    std::vector<std::pair<int, int>>& get_coors();
};

