#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check for input
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    //open file
    FILE *f = fopen(argv[1], "r");
    
    BYTE buffer[512];
    int inum = 0;
    FILE *img = NULL;
    char *filename = malloc(3);
    
    
    
    //copy to array
    while(fread(buffer, 512, 1, f))
    {
        //check header for jpeg
        if (img == NULL && buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 && inum == 000)
        {
            sprintf(filename, "%03i.jpg", inum);
            img = fopen(filename, "w");
            fwrite(buffer, 512, 1, img);
            inum++;
            
        }
        else if (img != NULL){
            fwrite(buffer, 512, 1, img);
        }
        else if (img != NULL && buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            fclose(img);
            sprintf(filename, "%03i.jpg", inum);
            img = fopen(filename, "w");
            fwrite(buffer, 512, 1, img);
            inum++;
        }
    }
    fclose(f);
    free(filename);
}
