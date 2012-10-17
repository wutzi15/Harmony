#ifndef HWHEEL_H
#define HWHEEL_H

#include "HColor.h"
#include "boost/cstdint.hpp"
#include <vector>
#include <memory>

typedef std::shared_ptr<HColor> color_ptr;

class HWheel {
public:
	HWheel(int seed);
	~HWheel();


private:
	float getYellow(float n);
	float getRed(float n);
	float getBlue(float n);
	float deg;
	float pos[8];
	std::vector<color_ptr> colors;
};


#endif