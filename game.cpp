#include "game.h"
game::game() {
	cam = camera(map_size, region_size, cam_width, cam_height);
	reg_gen = region_generator(map_size, region_size,
		planets_count, max_planets_radius, min_planets_radius, colors);
}
void game::run() {
	while (true) {
		reg_gen.update_regions(cam.get_visible_regions());
		cons.draw(cam, reg_gen);
		cam.input();
	}
}