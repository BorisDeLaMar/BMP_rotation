#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/transformation.h"

struct image* rotate( struct image* source, struct pixel** result, struct pixel** replica, struct bmp_header* header  ){

    size_t height = 0; size_t width = 0;
    for(size_t i = 0; i < source->height; i++){
        height = 0;
        for(size_t j = 0; j < source->width; j++){
            //printf("I, J, H, W: %zu %zu %zu %zu\n", i, j, height, width);
            //printf("AAAAA: %" PRIu64, source->width - i - 1);
            result[height][width] = replica[i][j];
            height++;
        }
        width++;
    }

    header->biHeight = source->width;
    header->biWidth = source->height;
    uint64_t padding = 4 - 3*header->biWidth%4;
    uint64_t bit_len= header->biWidth + padding;
    printf(" %" PRId64, bit_len);
    
    size_t counter = 0;
    for(size_t i = 0; i < header->biHeight; i++){
        for(size_t j = 0; j < header->biWidth; j++){
            (*source).data[counter] = result[i][j];
            counter++;
        }
        /*for(size_t j = 0; j < padding; j++){
            (*source).data[counter].b = 0;
            (*source).data[counter].g = 0;
            (*source).data[counter].r = 0;
            counter++;
        }*/
    }

    char* mass = malloc(sizeof(char)*padding);
    FILE* file = fopen("/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/tester/tests/1/test.bmp", "w");
    fwrite(header, 1, sizeof(struct bmp_header), file);
    //fwrite((*source).data, 1, sizeof(struct pixel)*bit_len*header->biHeight, file);
    //fwrite(result, 1, sizeof(struct pixel)*header->biWidth*header->biHeight, file);
    for(size_t i = 0; i < header->biHeight; i++){
        fwrite(result[i], 1, sizeof(struct pixel)*header->biWidth, file);
        fwrite(mass, 1, padding, file);
    }
    back_from_the_future(source, result);

    return source;
}