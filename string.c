#include "main.h"

int _strlen(char* word)
{
    int counter = 0;
    for (int i = 0; word[i] != '\0'; i++){
        counter++;
    }

    return counter;
}

char* _strdup(char* word){
    int wordLen;
    char* copy;

    wordLen = _strlen(word);
    copy = (char*)malloc((wordLen) * sizeof(char));

    if (copy == NULL) {
        return NULL; 
    }

    for(int i = 0; i < wordLen; i++){
        copy[i] = word[i];
    }

    copy[wordLen] = '\0';

    return copy;
}
