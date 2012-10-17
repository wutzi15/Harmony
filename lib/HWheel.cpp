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
		float n = pos[i];
		if (n <= 120 && n >= 0) {
			yellow = 100 -(100/120 * n);
		} else if (n >= 240 && n <=360) {
			yellow = 100 - (n - 240) * 100/120;
		} else {
			yellow = 0;
		}

		if (n <= 120 && n >= 0) {
			red = (100/120 * n);
		} else if (n < 240 && n >120) {
			red = 100 - (100/120 *(n-120));
		} else {
			red = 0;
		}

		if (n >= 120 && n <= 240) {
			blue = 120 - (100/120 * n);
		} else if (n >=240 && n <=360) {
			blue = 100 - (100/120 * (n-240));
		} else {
			blue = 0;
		}
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