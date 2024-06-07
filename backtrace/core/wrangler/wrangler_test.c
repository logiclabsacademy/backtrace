// Function to compare floating-point values
#include "wrangler.test.h"
bool are_close(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}