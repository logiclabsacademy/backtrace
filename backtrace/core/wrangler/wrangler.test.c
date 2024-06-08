#include <stdio.h>
#include <stdlib.h> 

#include "wrangler.h"

int main() {
    const char *text = "const char *code = 'printf(\"Hello, World!\");';";
    double entropy = compute_entropy(text);
    WImage *image = WImage_write_image(entropy, 10, 10);
    print_image(image);
    WImage_free(image);
    return 0;
}
