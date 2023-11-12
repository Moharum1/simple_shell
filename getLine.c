#include "main.h"
#include "string.h"

/**
  * _getline - read an input stream into a buffer
  * @buffer: reference to the a pointer where we will store the data
  * @buffersize: the size of the memory allocated by the buffer
  *
  * @return: characters read
*/
int _getline(char **buffer, int bufferSize)
{
	unsigned int counter = 0;
	char charRead = 0;
	/* allocate a buffer on the heap with the size given from the input*/
	*buffer = (char *)malloc(bufferSize * sizeof(char));

	if (*buffer == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	/* read a character as long as there is no EOF or Enter pressed */
	while ((charRead = getc(stdin)) != EOF && charRead != '\n')
	{

		/* increment the couter and derefernce the pointer to store string in it*/
		(*buffer)[counter++] = charRead;

		/* realloc if a space is needed */
		if (counter == bufferSize)
		{
			bufferSize = bufferSize + 10;
			*buffer = realloc(*buffer, bufferSize);
		}
	}

	/*add null termination char to state the end of the string*/
    return counter;

}
/*
int main(){
    char *buffer;
    char *token;

    _getline(&buffer, 10);

    token = strtok(buffer, " ");

    while(token != NULL){
        printf("%s\n",buffer);
        token = strtok(NULL, " ");
    }

    free(buffer);
}*/
