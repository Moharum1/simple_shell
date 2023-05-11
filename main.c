#include "main.h"


int main(int argc , char *argv[])
{
	char command[100];
	int len;
	/*int i;
	*/

	if (argc == 1)
	{
		while (1)
		{
			printf("#cisfun$ ");

			/* get the input from the user */
			fgets(command , sizeof(command), stdin);

			/* get the number of letters used from the array to 
			 * accss it later */
			len = strlen(command);

			/* handle the Ctrl+D when it is excuted without any 
			 * input */
			if (len == 0)
				return (0);
			else 
			{
				printf("./shell: %d" , len);
				printf("No such file or directory\n");
			}
		}
	}
	else 
	{
		printf("global input %s\n", argv[1]);
		printf("%d",argc);
	}


	return (0);
}
