#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"


int main(void)
{
    char* error = NULL;
    FILE * input_file = fopen("C:\\Users\\miled\\Desktop\\VENUS.bmp", "rb");
    FILE * output_file = fopen("C:\\Users\\miled\\Desktop\\new.bmp", "wb");

    BMPImage *image = read_bmp(input_file, &error);
    printf("%s",error);
    write_bmp(output_file,image, &error);



    fclose(input_file);
    fclose(output_file);
}
