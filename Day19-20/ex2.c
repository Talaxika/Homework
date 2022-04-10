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
    int arr[1000];
    FILE *fp = fopen(arg, "r");
    if (NULL == fp)
    {
        perror("file open problem");
        exit(-1);
    }

    while ((!feof(fp)) && n < 1000)
    {
        fscanf(fp, "%d", &arr[n++]);
    }

    fclose(fp);
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            swap(&arr[min], &arr[i]);
        }
    }
    FILE *fpw = fopen(arg, "w");
    for (int i = 0; i < n; i++)
    {
        fwrite(&arr[i], sizeof(int), sizeof(int), fp);
    }
    fclose(fpw);
}

int main(int argc, char **argv[])
{
    pthread_t threads[argc];

    for (int i = 1; i < argc-1; i++)
    {
        if (pthread_create(&threads[i], NULL, func, &argv[i]) != 0)
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
