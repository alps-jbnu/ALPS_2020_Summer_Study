#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef struct train_color {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} train_color_t;

train_color_t* reate_rgb_color_malloc(const uint8_t red, const uint8_t green, const uint8_t blue);