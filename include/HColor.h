#ifndef HCOLOR_H		
#define HCOLOR_H

#include "boost/cstdint.hpp"


class HColor {
public:
	HColor();

	void setRedGreenBlue(uint8_t r, uint8_t g, uint8_t b);
	uint8_t getRed_rgb();
	uint8_t getGreen_rgb();
	uint8_t getBlue_rgb();

	void setRedBlueYellow(uint8_t r, uint8_t b, uint8_t y);
	uint8_t getRed_rby();
	uint8_t getBlue_rby();
	uint8_t getYellow_rgy();

private:
	uint8_t r_rgb, g,r_gb, b_rgb;
	uint8_t r_rby, b_rby, y_rby;

};

#endif