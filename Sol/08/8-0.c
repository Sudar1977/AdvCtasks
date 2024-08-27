#include <stdio.h>
//#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>

#define DEBUG

#ifdef DEBUG
#define D printf("At line: %d\n", __LINE__);
#else
#define D
#endif

int main(int argc, char ** argv)
{
    //~ int fi = open("input.bin", O_RDONLY);
    //~ int fo = open("output.bin", O_WRONLY |O_CREAT,S_IRWXU);
    FILE* fi = fopen("input02.dat", "rb");
    FILE* fo = fopen("output.bin", "wb");

    uint16_t data;
    uint8_t offset;

    fseek (fi, -1, SEEK_END);
    uint32_t datasize = ftell(fi);

    int res;
    res = fread(&offset,1,1,fi);

#ifdef DEBUG
    printf("offset: %u datasize: %u\n", offset,datasize);
#endif
    res = fseek(fi, offset*2, SEEK_SET);
    for(int i = offset; i<datasize/2; i++)
    {
        res = fread(&data,sizeof(uint16_t),1,fi);
        res = fwrite(&data,sizeof(uint16_t),1,fo);
#ifdef DEBUG
        printf(",%u ", data);
#endif

    }
    fseek(fi, 0, SEEK_SET);
    for(int i = 0; i<offset; i++)
    {
        res = fread(&data,sizeof(uint16_t),1,fi);
        res = fwrite(&data,sizeof(uint16_t),1,fo);
#ifdef DEBUG
        printf(".%u ", data);
#endif
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
