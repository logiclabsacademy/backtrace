// Function to compare floating-point values
#include "wrangler.h"
#include "wrangler_test.h"

bool are_close(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}

double compute_entropy(const char *text) {
    int frequency[256] = {0};
    int length = strlen(text);

    // Calculate frequency of each character
    for (int i = 0; i < length; i++) {
        unsigned char ch = text[i];
        frequency[ch]++;
    }

    // Calculate entropy
    double entropy = 0.0;
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            double p = (double)frequency[i] / length;
            entropy -= p * log2(p);
        }
    }

    return entropy;
}

// Function to generate a WImage based on entropy
WImage* generate_image(double entropy, int width, int height) {
    WImage *image = (WImage *)malloc(sizeof(WImage));
    image->width = width;
    image->height = height;
    image->pixels = (WPixel *)malloc(width * height * sizeof(WPixel));

    // Populate pixels based on entropy
    for (int i = 0; i < width * height; i++) {
        unsigned int value = (unsigned int)(entropy * 255) % 256;
        image->pixels[i] = (WPixel){value, value, value};
    }

    return image;
}

// Function to print the image as ASCII art (for demonstration purposes)
void print_image(WImage *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            WPixel pixel = image->pixels[y * image->width + x];
            char intensity = ' ';
            if (pixel.r > 200) intensity = '@';
            else if (pixel.r > 150) intensity = '#';
            else if (pixel.r > 100) intensity = '*';
            else if (pixel.r > 50) intensity = ':';
            else intensity = '.';
            putchar(intensity);
        }
        putchar('\n');
    }
}