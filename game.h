#pragma once
#include "console.h"
class game
{
protected:
	const int map_size = 3;
	const int region_size = 100;
	const int planets_count = 50;
	const int max_planets_radius = 5;
	const int min_planets_radius = 1;
	const int cam_width = 80;
	const int cam_height = 30;
	std::vector<shape_color> colors{
		blue,
		green,
		aqua,
		red,
		purple,
		yellow,
	};
	camera cam;
	region_generator reg_gen;
	console cons;
public:
	game();
	void run();
};

