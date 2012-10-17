#include "HWheel.h"

#include <math>

HWheel::HWheel(float seed)
{
	deg = seed % 360;

	for (size_t i = 0; i < 4; i++) {
		pos[i] = (i * 90) + deg;
	}

	for (size_t i = 4; i < 8; i++) {
		pos[i] = (i * 90) + 45 + deg;
	}
	
	for (size_t i = 0; i < 8; i++) {
		auto c = std::make_shared<HColor>();
		float red,blue,yellow;
		if (deg <= 120) {
			yellow = 120 - (100/120 * deg);
		} else if (deg > 240) {
			yellow = (deg - 240) * 100/120;
		} else {
			yellow = 0;
		}

		if (deg)
	}	
}

HWheel::~HWheel()
{
	delete pos;
}

HWheel::getYellow(float n)
{
	if (n >)	
}