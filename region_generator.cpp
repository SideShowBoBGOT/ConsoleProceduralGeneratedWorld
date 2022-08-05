#include "region_generator.h"
void region_generator::erase_invisible_regions(std::vector<std::pair<int, int>>& visible_regions) {
	regions.erase(std::remove_if(regions.begin(), regions.end(),
		[this, &visible_regions](region& r) {
		return std::find(visible_regions.begin(), visible_regions.end(), r.get_reg())
			== visible_regions.end();
	}), regions.end());
}
void region_generator::add_visible_regions(std::vector<std::pair<int, int>>& visible_regions) {
	for (const auto& v_r : visible_regions) {
		if (std::find_if(regions.begin(), regions.end(),
			[&v_r](region& r) {return r.get_reg() == v_r;}) == regions.end()) {
			int seed = v_r.second * map_size + v_r.first; srand(seed);
			std::vector<std::shared_ptr<circle>> planets(planets_count);
			for (int i = 0; i < planets_count; i++)
				planets[i] = std::make_shared<circle>
				(circle(v_r.first * region_size + rand() % region_size,
					v_r.second * region_size + rand() % region_size,
					min_planets_radius + rand() % max_planets_radius,
					colors[rand() % colors.size()]));
			regions.push_back(region(std::move(planets), v_r));
		}
	}
}
region_generator::region_generator() {}
region_generator::region_generator(int map_size, int region_size, int planets_count,
	int max_planets_radius, int min_planets_radius,
	std::vector<shape_color> colors) :map_size{ map_size }, region_size{ region_size },
	planets_count{ planets_count }, max_planets_radius{ max_planets_radius },
	min_planets_radius{ min_planets_radius }, colors{ colors } {}
std::vector<region>& region_generator::get_visible_regions() { return regions; }
void region_generator::update_regions(std::vector<std::pair<int, int>>& visible_regions) {
	erase_invisible_regions(visible_regions);
	add_visible_regions(visible_regions);
}

