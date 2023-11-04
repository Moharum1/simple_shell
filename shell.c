#include "main.h"
extern char** environ;

int getArgumentNum(char* content,char* delim){

    strtok(content, delim);
    int counter = 0;

    while(strtok(NULL, delim) != NULL){
        counter++;
    }

    return counter;
}

void executeCommand(char *command, char *delim){

    int ArgNo;
    char *token;

    ArgNo = getArgumentNum(command, delim);

    char *Argv[ArgNo + 1];
    Argv[0] = get_Location(removeNewline(strtok(command, delim)));

    token = strtok(NULL, delim);

    for (int i = 1; i < ArgNo; i++){
        Argv[i] = removeNewline(token);
        token = strtok(NULL, delim);
    }

    Argv[ArgNo + 1] = NULL;

    if(execve(Argv[0], Argv, environ) == -1){
        perror("Error:");
        exit(EXIT_SUCCESS);
    }
}

char* removeNewline(char *str) {
    char *newline_position = strchr(str, '\n');
    if (newline_position != NULL) {
        *newline_position = '\0';
    }

    return str;
}

char* get_Location(const char *command) {
    char *pathContent = getenv("PATH");
    char *filePath, *pathToken;
    struct stat buffer;

    if (pathContent == NULL) {
        fprintf(stderr, "PATH environment variable not found.\n");
        return NULL;
    }

    pathToken = strtok(pathContent, ":");

    while (pathToken != NULL) {

    

        size_t dirLen = strlen(pathToken);
        size_t commandLen = strlen(command);

        /*Allocate memory to store the string that we will return.*/ 
        filePath = (char *)malloc((dirLen + commandLen + 2) * sizeof(char));
        
        if (filePath == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        strcpy(filePath, pathToken);
        strcat(filePath, "/");
        strcat(filePath, command);

        /*Test if the command exists in the executable file. If it does, return it.*/
        if (stat(filePath, &buffer) == 0) {
            return filePath;
        }

        free(filePath);
        pathToken = strtok(NULL, ":");
    }

    /* If the command wasn't found in any of the directories, check the current directory.*/
    if (stat(command, &buffer) == 0) {
        return strdup(command);
    }

    /*Check if the command is a local made commad*/
    localCommands(command);

    return NULL; 
}

void localCommands(const char* commad){
    if (strcmp(commad , "exit") == 0){
        printf("exit the app\n");
        exit(EXIT_SUCCESS);
    }
}