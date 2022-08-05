#pragma once
#include "region.h"
#include "camera.h"
class region_generator
{
protected:
	int map_size;
	int region_size;
	int planets_count;
	int max_planets_radius;
	int min_planets_radius;
	std::vector<region> regions;
	std::vector<shape_color> colors;
	void erase_invisible_regions(std::vector<std::pair<int, int>>& visible_regions);
	void add_visible_regions(std::vector<std::pair<int, int>>& visible_regions);
public:
	region_generator();
	region_generator(int map_size, int region_size, int planets_count,
		int max_planets_radius, int min_planets_radius,
		std::vector<shape_color> colors);
	std::vector<region>& get_visible_regions();
	void update_regions(std::vector<std::pair<int, int>>& visible_regions);
};

