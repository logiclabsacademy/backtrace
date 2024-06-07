#include <stdio.h>
#include <math.h>

#include "../core/wrangler/wrangler.h"



int main() {
    const char *text = "Hello, World!";
    double entropy = compute_entropy(text);
    printf("Computed entropy: %f\n", entropy);

    // Example test case: Known entropy for "Hello, World!"
    double expected_entropy = 3.180832; // Replace with the correct value
    if (are_close(entropy, expected_entropy, 0.0001)) {
        printf("Test passed!\n");
        return 0;
    } else {
        printf("Test failed! Expected: %f, Got: %f\n", expected_entropy, entropy);
        return 1;
    }
}
