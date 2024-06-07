// Author : Nnamdi Michael Okpala
// Description: Wrangler - Code Mangler and Demangler

#ifndef WRANGLER_H
#define WRANGLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


// A Wrangler Pixel
typedef struct WPixel_s WPixel;
struct WPixel {
    const unsigned int r,g,b,a;
};

// A wrangler image 
typedef struct WImage_s WImage;
struct WImage_s {
    const int width, height;
    WPixel *pixels;
};



#endif