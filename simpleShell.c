#include "main.h"
#include <stdbool.h>

int main(){

    /*
        declration for reading an input from the user
    */
    Buffer buffer;
    buffer.bufferSize = 30;
    bool from_pipe = false;

    char** tokens;
    char delim[2] = " ";


    int status;
    pid_t child_pid;

    

    buffer.content = (char *)malloc(buffer.bufferSize * sizeof(char));

    if (buffer.content == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }
    
    while(1  && !from_pipe ){

        if (isatty(STDIN_FILENO) == 0){
            from_pipe = true;
        }

        printf("$ ");
        getline(&(buffer.content), &(buffer.bufferSize),stdin);


        if (feof(stdin)){
            printf("exit\n");
            break;
        }
        
        tokens = CreateCommandArray(removeNewline(buffer.content), delim);
        tokens[0] = get_Location(tokens[0]);

        if(tokens[0] != NULL){
            if (!localCommands(tokens[0])){
                child_pid = fork();

                if (child_pid == -1)
                {
                    perror("Error:");
                    return (1);
                }

                if (child_pid == 0){
                    executeCommand(tokens);            
                }
            }
        }else{
            perror("Error");
        }
        


        
        wait(&status);
        freeTokens(tokens, getStringArraySize(tokens));   
        
    }
    free(buffer.content);
    return(0);
}
