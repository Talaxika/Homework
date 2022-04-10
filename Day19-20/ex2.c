#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void *func(void *arg)
{
    int i = 0, n = 0, min, index;
    char* filename = (char*)arg;
    FILE *fp = fopen(filename, "r");
    int size = ftell(fp);
    n = size/sizeof(int);
    if (NULL == fp)
    {
        perror("file open problem");
        exit(-1);
    }
    int *arr = (int*) malloc(size);

    while ((!feof(fp)))
    {
        fread((arr+i), sizeof(int), 1, fp);
    }

    fclose(fp);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(arr+j) > *(arr+min))
            {
                swap(&arr[min], &arr[i]);
            }
            
        }
    }
    FILE *fpw = fopen(filename, "wb");
    if (NULL == fpw)
    {
        perror("error fopen write");
        exit(-1);
    }
    
    for (int i = 0; i < n; i++)
    {
        fwrite((arr+i), sizeof(int), 1, fpw);
    }
    fclose(fpw);
    free(arr);
}

int main(int argc, char *argv[])
{
    pthread_t threads[argc-1];

    for (int i = 1; i < argc; i++)
    {
        if (pthread_create(&threads[i], NULL, func, argv[i]) != 0)
        {
            perror("create thread problem");
            return EXIT_FAILURE;
        }
    }
    for (int i = 1; i < argc-1; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("thread join problem");
            return EXIT_FAILURE;
        }
    }

    return 0;
}
