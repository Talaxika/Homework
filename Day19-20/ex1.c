#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

void* func(void* arg){
    char str[10];
    rand_string(str, 10);
    printf("%s\n", str);
}

int main() {
    int n;
    scanf("%d", &n);
    pthread_t threads[n];


    for (int i = 0; i < n; i++)
    {
        if(pthread_create(&threads[i], NULL, func, NULL) != 0){
            perror("create thread problem");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(pthread_join(threads[i], NULL) != 0){
            perror("thread join problem");
            return EXIT_FAILURE;
        }
    }

    return 0;
}
