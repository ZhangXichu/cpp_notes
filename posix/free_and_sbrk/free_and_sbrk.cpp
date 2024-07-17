#include "tlpi_hdr.hpp"


int main()
{
    char *ptr[MAX_ALLOCS];

    int free_step = 1;
    int free_min = 1;
    int free_max = 100;
    int num_allocs = 100;
    int block_size = 4;
    int i;

    printf("Initial program break: %10p\n", sbrk(0));

    printf("Allocating %d*%d bytes\n", num_allocs, block_size);

    for (int i = 0; i < num_allocs; i++)
    {
        ptr[i] = (char*)malloc(block_size);
        if (ptr[i] == NULL)
        {
            exit(EXIT_FAILURE);
        }
    }

    printf("Program break is now: %10p\n", sbrk(0));

    printf("Freeing blocks from %d to %d in steps of %d\n", free_min, free_max, free_step);

    for (int i = free_min - 1; i < free_max; i += free_step)
    {
        free(ptr[i]);
    }

    printf("after free(), program break is %10p\n", sbrk(0));

    exit(EXIT_SUCCESS);
}