#include "HColor.h"

void HColor::setRedBlueYellow(uint8_t r, uint8_t b, uint8_t y)
{
	r_rby = r;
	b_rby = b;
	y_rby = y;
}

void HColor::setRedGreenBlue(uint8_t r, uint8_t g, uint8_t b)
{
	r_rgb = r;
	g_rgb = g;
	b_rgb = b;
}

uint8_t HColor::getRed_rgb()
{
	return r_rgb;
}

uint8_t HColor::getGreen_rgb()
{
	return g_rgb;
}

uint8_t HColor::getBlue_rgb()
{
	return b_rgb;
}

uint8_t HColor::getRed_rby()
{
	return r_rby;
}

uint8_t HColor::getBlue_rby()
{
	return b_rby;
}

uint8_t HColor::getYellow_rby()
{
	return y_rby;
}