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
		if (n <= 120) {
			yellow = 100 -(100/120 * n);
		} else if (n > 240) {
			yellow = 100 - (n - 240) * 100/120;
		} else {
			yellow = 0;
		}

		if (n <= 120) {
			red = (100/120 * n);
		} else if (n < 240) {
			red = 100 - (100/120 *(n-120));
		} else {
			red = 0;
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