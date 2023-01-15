#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/imgStruct.h" 
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/bmpStruct.h"
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/util.h"

struct image* rotate( struct image* source, struct pixel** result, struct pixel** replica, struct bmp_header* header );

#endif /* TRANSFORMATION_H */