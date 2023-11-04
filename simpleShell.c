#include "main.h"

int main(){

    /*
        declration for reading an input from the user
    */
    Buffer buffer;
    buffer.bufferSize = 30;

    char delim[2] = " ";


    int status;
    pid_t child_pid;

    buffer.content = (char *)malloc(buffer.bufferSize * sizeof(char));
   if (buffer.content == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    while(1){
        printf("$ ");
        getline(&(buffer.content), &(buffer.bufferSize), stdin);

        if (feof(stdin)){
            printf("exit\n");
            break;
        }

        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }

        if (child_pid == 0){
            executeCommand((char *)(buffer.content), delim);
        }
    
        wait(&status);
    }

    free(buffer.content);
    return(0);
}
