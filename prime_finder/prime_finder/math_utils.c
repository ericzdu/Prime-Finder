#include "header.h"

float fast_overshoot_sqrt(int x) {
	union {
		float f;
		uint32_t i;
	} conv;

	conv.f = (float)x;
	conv.i = (conv.i >> 1) + 0x1FE6A09E;  // Biased to overshoot, goal is to overshoot as little as possible while still being efficient
	return conv.f;
}