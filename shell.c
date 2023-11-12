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

void executeCommand(char** Argv){
   
    if(execve(Argv[0], Argv, environ) == -1){
            perror("Error: (execve)");
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

char* get_Location(char *command) {
    
    char *pathContent = _strdup(getenv("PATH"));
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
            free(pathContent);
            return filePath;
        }

        free(filePath);
        pathToken = strtok(NULL, ":");
    }

    free(pathContent);

    /* If the command wasn't found in any of the directories, check the current directory.*/
    if (stat(command, &buffer) == 0) {
        return _strdup(command);
    }

    return NULL; 
}

bool localCommands(char* command){
    if (command == NULL) {
        fprintf(stderr, "Command is NULL.\n");
        return false;
    }

    if (strcmp(command, "exit") == 0){
        exit(EXIT_SUCCESS);
    } else if (strcmp(command , "env") == 0){
        if (environ == NULL) {
            fprintf(stderr, "Environment variables not found.\n");
            return false;
        }
        for (char** env = environ; *env != NULL; env++) {
            printf("%s\n", *env);
        }
        return true;
    }
    return false;
}

char** CreateCommandArray(char* command, char* delim){
    
    int tokenCount;
    char** tokens;
    char* token;

    tokenCount = 1;

    for(int i = 0; command[i] != '\0'; i++){
        if (command[i] == *delim){
            tokenCount++;
        }
    }

    tokens = (char**)malloc( tokenCount * sizeof(char*));

    if (tokens == NULL) {
        perror("Error in malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, delim);
    int i = 0;

    while(token != NULL){
        tokens[i] = _strdup(token);

        // Check if strdup was successful
        if (tokens[i] == NULL) {
            perror("Error in strdup");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, delim);
        i++;
    }

    return tokens;
}

void freeTokens(char** tokens, int tokenCount){
    for (int i = 0; i < tokenCount; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

int getStringArraySize(char** array){
    
    int counter = 0;
    for (int i = 0; array[i] != NULL; i++) {
        counter++;
    }

    return counter;
}