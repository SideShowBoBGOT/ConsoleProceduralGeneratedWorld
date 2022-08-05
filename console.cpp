#include "console.h"
std::vector<std::shared_ptr<circle>> console::get_visible_planets(camera& cam, region_generator& reg_gen) {
	std::vector<region>& visible_regions = reg_gen.get_visible_regions();
	std::vector<std::pair<int, int>>& cam_coors = cam.get_coors();
	std::vector<std::shared_ptr<circle>> visible_planets;
	std::for_each(visible_regions.begin(), visible_regions.end(),
		[&visible_regions, &cam_coors, &visible_planets](region& r) {
		std::vector<std::shared_ptr<circle>>& planets = r.get_planets();
		std::for_each(planets.begin(), planets.end(),
			[&cam_coors, &visible_planets](std::shared_ptr<circle>& p) {
			std::vector<std::pair<int, int>>& coors = p->get_coors();
			if (std::find_if(coors.begin(), coors.end(), [&cam_coors](std::pair<int, int>& c) {
				return std::find(cam_coors.begin(), cam_coors.end(), c) != cam_coors.end();
			}) != coors.end()) {
				visible_planets.push_back(p);
			}
		}
		);
	});
	return visible_planets;
}
console::console() {}
void console::draw(camera& cam, region_generator& reg_gen) {
	std::vector<std::shared_ptr<circle>> planets = get_visible_planets(cam, reg_gen);
	std::vector<region>& visible_regions = reg_gen.get_visible_regions();
	int width = cam.get_width(), height = cam.get_height();
	int x = cam.get_x(), y = cam.get_y();
	std::cout.flush();
	SetConsoleCursorPosition(consl, coord);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			auto pl = std::find_if(planets.begin(),
				planets.end(), [x, y, i, j, &cam](std::shared_ptr<circle> p) {
				std::vector<std::pair<int, int>>& coors = p->get_coors();
				int current_x = cam.get_updated_coor(x + j);
				int current_y = cam.get_updated_coor(y + i);
				std::pair<int, int> c = std::pair<int, int>(current_x, current_y);
				return std::find(coors.begin(), coors.end(), c) != coors.end();
			});
			if (pl != planets.end())
				SetConsoleTextAttribute(consl, (*pl)->get_color());
			std::cout << ' ';
			SetConsoleTextAttribute(consl, shape_color::black);
		}
		std::cout << "    ";
		if (i == 5)
			std::cout << "Visible regions";
		if (i == 6)
			std::for_each(visible_regions.begin(), visible_regions.end(),
				[](region& r) {
			std::cout << "(" << r.get_reg().first << ", " << r.get_reg().second << ") ";
		});
		std::cout << "                    ";
		std::cout << '\n';
	}
	std::cout << "x: " << cam.get_x() << "    " << "y: " << cam.get_y() << "    ";
}
