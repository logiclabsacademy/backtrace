// Function to compare floating-point values
#ifndef WRANGLER_TEST_H
#define WRANGLER_TEST_H

#include "wrangler.h"
#include <math.h>

bool are_close(double a, double b, double epsilon);
WImage* generate_image(double entropy, int width, int height);
void print_image(WImage *image);
double compute_entropy(const char *text);

#endif // WRANGLER_TEST_H