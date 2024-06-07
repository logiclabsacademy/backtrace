
#include "wrangler.h"

// Main function

int main() {
    // Example input string
    const char *text = "Hello, World!";
    
    // Calculate entropy
    double entropy = compute_entropy(text);
    printf("Entropy: %f\n", entropy);
    
    // Generate image
    int width = 10, height = 10;
    WImage *image = generate_image(entropy, width, height);
    
    // Print image (ASCII representation)
    print_image(image);
    
    // Free allocated memory
    free(image->pixels);
    free(image);
    
    return 0;
}
