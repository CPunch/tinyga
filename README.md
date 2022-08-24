# tinyga

just a tiny TGA image format writer with exclusive support for 24bit raw uncompressed RGB image data for simple graphics generation in C89. if you really only need to write simple images from generated data, this is perfect. anything that needs support for reading/parsing TGA files should look elsewhere.

## Usage

include `src/tinyga.h` && `src/tinyga.c` in your project.

an example of writing a simple TGA file:
```C
#include "tinyga.h"

#include <stdio.h>

#define WIDTH   1028
#define HEIGHT  1028
#define BOXSIZE 100

int main()
{
    TGA tga = TGANew(WIDTH, HEIGHT, TGACOLOR(200, 200, 200));
    TGAErrorCode err;

    /* draw a lil box :D */
    TGAFillColor(&tga, WIDTH / 2 - (BOXSIZE / 2), HEIGHT / 2 - (BOXSIZE / 2), BOXSIZE, BOXSIZE,
                 TGACOLOR(100, 100, 100));

    /* write to file */
    if ((err = TGADumpFile(&tga, "out.tga")) != TGA_OK) {
        printf("Failed to write TGA file! [%s]\n", TGAError2Str(err));
        return 1;
    }

    TGAClose(&tga);
    return 0;
}
```

Build the example project using:
```sh
> make && ./bin/tinyga
```
