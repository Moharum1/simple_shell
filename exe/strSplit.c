#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    size_t bufferSize = 50;
    char *buffer = NULL;  // Initialize the pointer
    char *lineContent;
    char delim[2] = " ";  // Corrected the delimiter to be a string

    while (1){
        printf("$: ");

        buffer = (char *)malloc(bufferSize * sizeof(char));
            if( buffer == NULL)
        {
        perror("Unable to allocate buffer");
        exit(1);
        }

        getline(&buffer, &bufferSize, stdin);

        /*Split the String into array*/
        /*get the 1st String*/
        lineContent = strtok(buffer, delim);

        /*Iterate throught the rest*/
        while( lineContent != NULL ) {
            printf("%s\n", lineContent);
            lineContent = strtok(NULL, delim);
        }

        free(buffer);
        
    }
}