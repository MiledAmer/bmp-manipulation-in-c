#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define BMP_HEADER_SIZE 54
#define DIB_HEADER_SIZE 40

#pragma pack(push)  //save the original data alignment
#pragma pack(1)     //set the data alignment to 1 byte boundary

// uint16_t is a 16bit unsigned int
// uint32_t is a 32bit unsigned int

typedef struct
{
    uint16_t type;
    uint32_t fsize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
    uint32_t dib_header_size;
    int32_t width_px;
    int32_t height_px;
    uint16_t num_planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size_bytes;
    int32_t x_resolution_ppm;
    int32_t y_resolution_ppm;
    uint32_t num_colors;
    uint32_t important_colors;
}BMPHeader;

#pragma pack(pop)

typedef struct
{
    BMPHeader header;
    unsigned char* data;
} BMPImage;

BMPImage* read_bmp(FILE* fp, char** error);
bool check_bmp_header(BMPHeader* bmp_header, FILE *fp);
bool write_bmp(FILE *fp, BMPImage* image, char** error);
void free_bmp(BMPImage* image);
BMPImage* crop_bmp(BMPImage* image, int x, int y, int w, int h, char** error);

#endif // BMP_H_INCLUDED
