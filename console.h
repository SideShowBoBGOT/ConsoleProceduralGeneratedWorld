#pragma once
#include <algorithm>
#include <iostream>
#include <Windows.h>
#include "region_generator.h"
#include "camera.h"
class console
{
private:
	COORD coord = { 0, 0 };
	HANDLE consl = GetStdHandle(STD_OUTPUT_HANDLE);
	std::vector<std::shared_ptr<circle>> get_visible_planets(camera& cam, region_generator& reg_gen);
public:
	console();
	void draw(camera& cam, region_generator& reg_gen);
};


