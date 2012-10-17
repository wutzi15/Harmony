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
	std::vector<color_ptr> getColors(){
		return colors;
	};

private:
	float deg;
	float pos[8];
	std::vector<color_ptr> colors;
};


#endif