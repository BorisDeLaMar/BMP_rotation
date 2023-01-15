// +files stdin, stdout, stderr
#include "/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/solution/include/fileOpening.h"



void file_opening(FILE** array){
    FILE* input = fopen("/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/tester/tests/1/input.bmp", "r");
    FILE* output = fopen("/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/tester/tests/1/output.bmp", "w");
    FILE* err = fopen("/home/borisdelamar/Labs/Labs_C/assignment-image-rotation/tester/tests/1/err.txt", "w");
    array[0] = input; array[1] = output; array[2] = err;
}
