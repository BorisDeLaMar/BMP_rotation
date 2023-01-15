#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/fileOpening.h"
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/bmpStruct.h"
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/imgStruct.h"
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/util.h"
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/transformation.h"

int main( int argc, char** argv ) {
    (void) argc; (void) argv; // supress 'unused parameters' warning

    FILE** array = malloc(sizeof(FILE*)*3);
    struct bmp_header* header = malloc(sizeof(struct bmp_header)); 

    file_opening(array);
    enum read_status header_st = from_bmp_header(array[0], header);

    struct image* img = malloc(sizeof(struct image));
    img->data = malloc(sizeof(struct pixel)*header->biHeight*header->biWidth);

    enum read_status img_st = from_bmp_image(array[0], img, *header);
    
    struct pixel** matrix = (struct pixel**) malloc(sizeof(struct pixel*)*img->width);
    for(int i = 0; i < img->width; i++) {
        matrix[i] = (struct pixel*) malloc(sizeof(struct pixel)*img->height);
    }
    

    struct pixel** matrix2 = (struct pixel**) malloc(sizeof(struct pixel*)*img->height);
    for(int i = 0; i < img->height; i++) {
        matrix2[i] = (struct pixel*) malloc(sizeof(struct pixel)*img->width);
    }
    matrix2 = mass_terraforming(img, matrix2);

    FILE* file = fopen("/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/tester/tests/1/test1337.bmp", "w");
    fwrite(header, 1, sizeof(struct bmp_header), file);
    for(size_t i = 0; i < header->biHeight; i++){
        fwrite(matrix2[i], 1, sizeof(struct pixel)*header->biWidth, file);
        //fwrite(mass, 1, padding, file);
    }

    img = rotate(img, matrix, matrix2, header);
    //img->data = *matrix2;
    //back_from_the_future(img, matrix2);

    //header->biHeight = img->width;
    //header->biWidth = img->height;
    to_bmp(array[1], img, header);

    return 0;
}
