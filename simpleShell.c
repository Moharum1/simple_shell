#include "main.h"

int main(void)
{
	/*declration for reading an input from the user*/
	Buffer buffer;
	char *delim;

	buffer.bufferSize = 30;

	delim = " ";

	buffer.content = (char *)malloc(buffer.bufferSize * sizeof(char));

	if (buffer.content == NULL)
	{
		perror("hsh");
		exit(1);
	}

	if (isatty(STDIN_FILENO) == 0)
	{
		while (getline(&(buffer.content), &(buffer.bufferSize), stdin) != EOF)
			exe(buffer.content, delim);

	}
	else
	{
		while (1)
		{
			printf("$ ");

			if (getline(&(buffer.content), &(buffer.bufferSize), stdin) == EOF)
			{
				free(buffer.content);
				exit(EXIT_SUCCESS);
			};

			exe(buffer.content, delim);
		}
	}
	free(buffer.content);
	return (0);
}

void exe(char *content, char *delim)
{
	int status;
	pid_t child_pid;
	char **tokens;
	char *mainCommand;

	tokens = CreateCommandArray(removeNewline(content), delim);

	if (tokens[0] == NULL)
	{
		freeTokens(tokens, getStringArraySize(tokens));
		return;
	}

	if (localCommands(tokens, content) == false)
	{

		mainCommand = _strdup(tokens[0]);
		free(tokens[0]);
		tokens[0] = get_Location(mainCommand);
		free(mainCommand);

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("hsh");
			return;
		}

		if (child_pid == 0)
			executeCommand(tokens);
	}
	else
		perror("hsh");

	wait(&status);
	freeTokens(tokens, getStringArraySize(tokens));

}

