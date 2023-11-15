#include "main.h"


/**
* getArgumentNum - a function to get the number of Argument in an array
* @content: the command you want to get the no of argument from
* @delim: the char that will be used to calculate the no. of commands
* @return : the number of arguments
*/
int getArgumentNum(char *content, char *delim)
{
	int counter;

	strtok(content, delim);
	counter = 1;

	while (strtok(NULL, delim) != NULL)
	{
		counter++;
	}

	return (counter);
}

/**
* executeCommand - execute a shell command or a exe file
* @argv: the argument you want to execute
* @return : none
*/
void executeCommand(char **Argv)
{
	if (execve(Argv[0], Argv, environ) == -1)
	{
		perror("hsh");
		exit(EXIT_SUCCESS);
	}
}

/**
* removeNewline - remove \n and replace it with null terminator
* @str: the string you want to edit
* @return : the new String with the remove space
*/
char *removeNewline(char *str)
{
	char *newline_position = _strchr(str, '\n');

	if (newline_position != NULL)
	{
		*newline_position = '\0';
	}

	return (str);
}

/**
* get_Location - check the path of the command you want to run
* @command: the command you want to search for it's path
* @return : the new command with the path
*/
char *get_Location(char *command)
{
	char *pathContent = _strdup(getenv("PATH"));
	char *filePath, *pathToken;
	struct stat buffer;

	if (pathContent == NULL)
	{
		free(pathContent);
		return (NULL);
	}
	pathToken = strtok(pathContent, ":");
	while (pathToken != NULL)
	{
		size_t dirLen = _strlen(pathToken);
		size_t commandLen = _strlen(command);
		/*Allocate memory to store the string that we will return.*/
		filePath = (char *)malloc((dirLen + commandLen + 2) * sizeof(char));
		if (filePath == NULL)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
		_strcpy(filePath, pathToken);
		_strcat(filePath, "/");
		_strcat(filePath, command);
		/*Test if the command exists in the executable file. If it does, return it.*/
		if (stat(filePath, &buffer) == 0)
		{
			free(pathContent);
			return (filePath);
		}
		free(filePath);
		pathToken = strtok(NULL, ":");
	}
	free(pathContent);
	/* Check if the command in current dir*/
	if (stat(command, &buffer) == 0)
	{
		return (_strdup(command));
	}
	return (NULL);
}

/**
* localCommands - execute some local command line arguments
* @command: the local command you want to execute
* @return : a bool statement if the command exists or not
*/
bool localCommands(char *command)
{
	char **env;

	if (command == NULL)
	{
		return (false);
	}

	if (_strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(command, "env") == 0)
	{
		if (environ == NULL)
		{
			return (false);
		}
		for (env = environ; *env != NULL; env++)
		{
			printf("%s\n", *env);
		}

		return (true);
	}
	return (false);
}

