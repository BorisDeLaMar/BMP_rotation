#ifndef UTIL_H_
#define UTIL_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/imgStruct.h"
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/bmpStruct.h"

struct pixel** mass_terraforming(struct image* img, struct pixel** perfect_array);
void back_from_the_future(struct image* img, struct pixel** perfect_array);

#endif /* UTIL_H_ */