#ifndef HCOLOR_H		
#define HCOLOR_H

#include "boost/cstdint.hpp"

template <typename T>
class HColor {
public:
	HColor();

	void setRedGreenBlue(T r, T g, T b);
	T getRed_rgb();
	T getGreen_rgb();
	T getBlue_rgb();

	void setRedBlueYellow(T r, T b, T y);
	T getRed_rby();
	T getBlue_rby();
	T getYellow_rgy();

private:
	T r_rgb, g,r_gb, b_rgb;
	T r_rby, b_rby, y_rby;

};

#endif