#include <stdio.h>


int main(int argc, char **argv)
{
    union 
    {
        short s;
        char c[sizeof(short)];
    }un;

    un.s = 0x1234;

    if (sizeof(short) == 2)
    {
        if ((un.c[0] == 0x12 && un.c[1] == 0x34))
        {
            printf("Big Endian\n");
        } else if ((un.c[0] == 0x34 && un.c[1] == 0x12))
        {
            printf("Little Endian\n");
        } else
        {
            printf("Unknown\n");
        }
    } else 
    {
        printf("sizeof(short) = %ld\n",sizeof(short));
    }

    return 0;
}