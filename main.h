#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void executeCommand(char *command, char *delim);
char* removeNewline(char *str);
int getArgumentNum(char* content,char* delim);
char* get_Location(char const *command);
void localCommands(const char*  commad);

typedef struct {
    size_t bufferSize;
    char *content;
} Buffer;

#endif