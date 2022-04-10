#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){

    if (argc == 1)
    {
        printf("Wrong input.");
        exit(-1);
    }
    
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        perror("pipe errors");
        exit(-1);
    }
    
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork problems");
        exit(-1);
    }
    else if (pid == 0)
    {
        close(pipefd[0]);
        int sum = 0;
        for (int i = 0; i < argc/2; i++)
        {
            sum+= atoi(argv[i]);

        }
        printf("Sum of child %d\n", sum);
        write(pipefd[1], &sum, sizeof(int));
        close(pipefd[1]);
        exit(0);
    }
    close(pipefd[1]);
    int sum2 = 0;
    for (int i = argc/2; i < argc; i++)
    {
        sum2+=atoi(argv[i]);
    }
    printf("Sum of parent %d\n", sum2);
    wait(NULL);
    
    int childsum;
    
    read(pipefd[0], &childsum, sizeof(int));
    printf("childsum = %d\n", childsum);
    

    sum2+=childsum;
    printf("Sum = %d\n", sum2);
    close(pipefd[0]);
    
    return 0;
}
