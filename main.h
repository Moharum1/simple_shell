#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>

void exe(char *content, char *delim);

int _strlen(char *word);
char *_strdup(char *word);
void _strcpy(char *destination, char *source);
void _strcat(char *content, char *addition);
char *_strchr(char *str, char character);
int _strcmp(const char *str1, const char *str2);

char **CreateCommandArray(char *const command, char *delim);
void freeTokens(char **tokens, int tokenCount);
int getStringArraySize(char **array);

void executeCommand(char **Argv);
char *removeNewline(char *str);
int getArgumentNum(char *content, char *delim);
char *get_Location(char *command);
bool localCommands(char *commad);
int _getline(char **buffer, int bufferSize);

typedef struct
{
	size_t bufferSize;
	char *content;
} Buffer;

extern char **environ;
#endif

