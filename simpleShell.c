#include "main.h"

int main(void)
{
	/*declration for reading an input from the user*/
	Buffer buffer;

	buffer.bufferSize = 30;

	char delim[2] = " ";

	buffer.content = (char *)malloc(buffer.bufferSize * sizeof(char));

	if (buffer.content == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	if (isatty(STDIN_FILENO) == 0)
	{
		getline(&(buffer.content), &(buffer.bufferSize), stdin);
		exe(buffer.content, delim);
	}
	else
	{
		while (1)
		{
			printf("$ ");

			if (getline(&(buffer.content), &(buffer.bufferSize), stdin) == EOF)
			{
				printf("exit\n");
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

	tokens = CreateCommandArray(removeNewline(content), delim);
	tokens[0] = get_Location(tokens[0]);

		if (tokens[0] != NULL)
		{
			if (!localCommands(tokens[0]))
			{
				child_pid = fork();

				if (child_pid == -1)
				{
					perror("Error:");
					return;
				}

				if (child_pid == 0)
					executeCommand(tokens);
			}
		}
		else
			perror("Error");

		wait(&status);
		freeTokens(tokens, getStringArraySize(tokens));

}

