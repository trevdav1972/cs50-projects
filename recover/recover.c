#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    FILE *inptr = fopen(argv[1],"r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    FILE *outptr = NULL;
    int jpg = 0;
    typedef uint8_t BYTE;
    char filename[8];
    BYTE BUFFER[512];
    while (fread(BUFFER, 1, 512, inptr) == 512)
    {
        if (BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] & 0xf0) == 0xe0)
        {
            if  (outptr != NULL)
            {
                fclose(outptr);
            }
            sprintf(filename, "%03d.jpg", jpg++);
            outptr = fopen(filename, "w");
        }
        if (outptr != NULL)
        {
            fwrite(BUFFER, 512, 1, outptr);
        }
    }
    fclose (outptr);
    fclose (inptr);

}