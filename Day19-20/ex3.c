#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *func(void *arg)
{
    char buff[100];
    strcpy(buff, arg);
    printf("%s\n", buff);
}

int main(int argc, char *argv[])
{
    int p = *argv[1] - 48;
    int t = *argv[2] - 48;
    pthread_t threads[t];
    for (int i = 0; i < p; i++)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork problem");
            exit(-1);
        }
        else if (pid == 0)
        {
            for (int i = 0; i < t; i++)
            {
                if (pthread_create(&threads[i], NULL, func, argv[3]) != 0)
                {
                    perror("create thread problem");
                    return EXIT_FAILURE;
                }
            }
            for (int i = 0; i < t; i++)
            {
                if (pthread_join(threads[i], NULL) != 0)
                {
                    perror("thread join problem");
                    return EXIT_FAILURE;
                }
            }
            exit(-1);
        }
    }

    return 0;
}
