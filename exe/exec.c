#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - fork example
 *
 * Return: Always 0.

int main(void)
{
    pid_t child_pid;
    char *execute[] = {"/bin/ls", "-l", "/tmp", NULL};
    int status;
    int processNum = 5;
    int subprocessNum = 1;

    printf("Before forking\n");

   
    
    for (int i = 0; i < processNum; i++ ){
    
        child_pid = fork();
        if (child_pid == -1)
        {
        perror("Error:");
        return (1);
        }

       if (child_pid == 0 ){
            if (execve(execute[0], execute, NULL) == -1)
            {
                perror("Error:");
                break;
            }
       }else{
            wait(&status);
            printf("we are at process : %d\n", subprocessNum);
            printf("process is done executing\n");
            printf("\n");
            subprocessNum++;
       }
        
    }

    return (0);
}*/

#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    return (0);
}