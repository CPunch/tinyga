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
    if ((err = TGADumpFile(&tga, "out.tga")) != TGA_OK) {
        printf("Failed to write TGA file! [%s]\n", TGAError2Str(err));
        return 1;
    }

    TGAClose(&tga);
    return 0;
}