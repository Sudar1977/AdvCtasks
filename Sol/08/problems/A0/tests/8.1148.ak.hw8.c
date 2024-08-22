#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

#ifdef DEBUG
#define D printf("At line: %d\n", __LINE__);
#else
#define D
#endif

//int main(int argc, char ** argv)
int main()
{
    FILE *fi , *fo;//= open("input.bin",'r');

    uint16_t data;

    uint8_t offset;

    if( (fi = fopen("input01.dat","r")) == NULL) {
        printf("error read");
    }
    if( (fo = fopen("output01.dat","w")) == NULL) {
        printf("error read");
    }
    unsigned int datasize = fseek (fi, -1, SEEK_END);
    fread(fi, &offset, 1);

    fseek(fi, offset*2, SEEK_SET);
    for(int i = offset; i<datasize/2; i++)
    {
        fread(fi, &data, 2);
        fwrite(fo, &data, 2);
    }
    lseek(fi, 0, SEEK_SET);
    for(int i = 0; i<offset; i++)
    {
        fread(fi, &data, 2);
        fwrite(fo, &data, 2);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
