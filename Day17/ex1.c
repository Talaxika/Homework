#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

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

int main(int argc, char* argv[]){
    if (argc != 2)
    {
        printf("Wrong input");
        exit(-1);
    }
    int n = atoi(argv[1]);
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("forking failed");
            exit(-1);
        }
        else if (pid == 0)
        {
            char buff[10];
            rand_string(buff, 10);
            printf("%s\n", buff);
            exit(0);
        }
        wait(NULL);
    }
  return 0;
}
