// Author : Nnamdi Michael Okpala
// Description: Wrangler - Code Mangler, and Demangler

#ifndef WRANGLER_H
#define WRANGLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

// A Wrangler Pixel
typedef struct WPixel_s {
     unsigned int r, g, b;
} WPixel;

// A Wrangler image 
typedef struct WImage_s {
    int width, height;
    WPixel *pixels;
} WImage;

// Function prototypes
double compute_entropy(const char *text);
WImage* WImage_write_image(double entropy, int width, int height);
void WImage_free(WImage *image);
void print_image(WImage *image);

#endif // WRANGLER_H




