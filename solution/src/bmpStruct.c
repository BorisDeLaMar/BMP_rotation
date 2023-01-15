#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/bmpStruct.h"

/*  deserializer   */

enum read_status from_bmp_header( FILE* in, struct bmp_header* header ){
  uint16_t read_header_bytes = fread(header, sizeof(struct bmp_header), 1, in);  
  if(read_header_bytes == sizeof(struct bmp_header)){
    return READ_OK;
  }
  else{
    return READ_ERROR;
  }
}

enum read_status from_bmp_image( FILE* in, struct image* img, struct bmp_header header ){

  img->height = header.biHeight;
  img->width = header.biWidth;
  uint64_t padding = 4 - 3*img->width%4;
  uint64_t bit_len = img->width+padding;
  printf("%" PRId64, bit_len);

  //unsigned char* data = malloc(sizeof(struct pixel)*img->height*img->width);

  /*unsigned char** data = malloc(sizeof(char)*img->height*img->width*3);
  uint64_t read_bytes = fread(data, 1, sizeof(char)*img->width*3*img->height, in);
  if(read_bytes != img->width*3*img->height){
    printf("KATASTROF");
  }*/
  /*uint64_t read_bytes = fread(data, 1, sizeof(struct pixel)*img->height*img->width, in);
  if(read_bytes != img->width*img->height*3){
    printf("KATASTROF");
  }*/

  //uint64_t read_bytes = fread(data, 1, img->height*bit_len, in);

  /*size_t j = 0;
  size_t h = 0;
  for(size_t i = 0; i < img->height*img->width; i++){
    if(((j-(j/img->height)*bit_len)%(img->width) == 0)){
      j += padding;
      size_t k = 0;
      while(k < padding){
        img->data[i+k].b = 0;
        img->data[i+k].g = 0;
        img->data[i+k].r = 0;
        k++;
      }
      h++;
      i += padding;
      //i += padding;
    }
    img->data[i].b = data[j];
    j++;
    img->data[i].g = data[j];
    j++;
    img->data[i].r = data[j];
    j++;
  }*/
  //printf("%" PRId64, img->height);

  for(size_t i = 0; i < img->height; i++){
    fread(img->data + img->width*i, sizeof(struct pixel), img->width, in);
    fseek(in, padding, SEEK_CUR);
  }

  FILE* file = fopen("/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/tester/tests/1/test228.bmp", "w");
  fwrite(&header, 1, sizeof(struct bmp_header), file);
  unsigned char* mass = malloc(sizeof(char)*padding);
  for(size_t i = 0; i < img->height; i++){
    fwrite(img->data + img->width*i, sizeof(struct pixel), img->width, file);
    fwrite(mass, 1, padding, file);
  }
  //fwrite(img->data, 1, sizeof(struct pixel)*img->height*img->width, file);
  return READ_OK;
}

/*  serializer   */

enum write_status to_bmp( FILE* out, struct image const* img, struct bmp_header* header ){
  fwrite(header, 1, sizeof(struct bmp_header), out);

  uint64_t padding = 4 - 3*header->biWidth%4;
  char* mass = malloc(sizeof(char)*padding);

  for(size_t i = 0; i < header->biHeight; i++){
    fwrite(img->data + header->biWidth*i, sizeof(struct pixel), header->biWidth, out);  
    fwrite(mass, 1, padding, out);
  }
  return WRITE_OK;
}
