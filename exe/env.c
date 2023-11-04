#include <stdio.h>
#include <string.h>
extern char** environ;

char *_getenv(const char *name);
void getPathContent();
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[], char *env[]) {

    getPathContent();

    return 0;
}

char *_getenv(const char *name){
    size_t i;
    for(i = 0 ; environ[i] != NULL; i++){
        if (strstr(environ[i],name) != NULL){
            return strstr(environ[i],name);
        }
    }
    return NULL;
}

void getPathContent(){
    char *content;
    char *lineContent;
    char delim[2] = ":";

    content = _getenv("PATH");
    lineContent = strtok(content, delim);


    while(lineContent != NULL){
        printf("%s\n",lineContent);
        lineContent = strtok(NULL, delim);
    }

}