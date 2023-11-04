#include <stdio.h>
#include <stdlib.h>

int main(){

    size_t bufferSize = 50;
    char *buffer;

    while (1){
        printf("$: ");

        buffer = (char *)malloc(bufferSize * sizeof(char));
            if( buffer == NULL)
        {
        perror("Unable to allocate buffer");
        exit(1);
        }

        getline(&buffer, &bufferSize, stdin);
        printf("%s", buffer);
        free(buffer);
        
    }
}