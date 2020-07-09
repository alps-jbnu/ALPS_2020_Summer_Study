#include "train_color.h"
#include <stdio.h>

train_color_t* reate_rgb_color_malloc(const uint8_t red, const uint8_t green, const uint8_t blue) 
{
	train_color_t* returnVal = NULL;
	returnVal = (train_color_t*)malloc(sizeof(train_color_t));

	//실패 여부 확인
	if (returnVal == NULL) {
		printf("Fail to color memory allocation");
	}
	else {
		returnVal->red = red;
		returnVal->green = green;
		returnVal->blue = blue;
	}
	return returnVal;
}