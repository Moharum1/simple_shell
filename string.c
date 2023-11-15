#include "main.h"


/**
 * _strchr - get the position of a char in string
 * @str: the string you will use for search
 * @character: the char you want to find
 * @return: pointer to the char if exist
 */
char *_strchr(char *str, char character)
{
	while (*str != '\0')
	{
		if (*str == character)
			return (str);
		str++;
	}

	return (NULL);
}

/**
 * _strlen - get the lenght of a string
 * @word: the word you want to get it's length
 * @return: the number of char in the string
 */
int _strlen(char *word)
{
	int i;
	int counter = 0;

	for (i = 0; word[i] != '\0'; i++)
	{
		counter++;
	}

	return (counter);
}

/**
*_strdup - duplicate a string
* @word: String you want to duplicate
* @return: pointer to the duplicated string
*/
char *_strdup(char *word)
{
	int wordLen;
	int i;
	char *copy;

	wordLen = _strlen(word);
	copy = (char *)malloc((wordLen) * sizeof(char));

	if (copy == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < wordLen; i++)
	{
		copy[i] = word[i];
	}

	copy[wordLen] = '\0';

	return (copy);
}

/**
*_strcpy - copy the content of a string into another string
* @destination: String you want to copy
* @source: String you want to copy the text into
* @return : none
*/
void _strcpy(char *destination, char *source)
{
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

}
/**
*_strcpy - copy the content of a string into another string
* @destination: String you want to copy
* @source: String you want to copy the text into
* @return : none
*/
void _strcat(char *content, char *addition)
{
	while (*content != '\0')
	{
		content++;
	}

	while (*addition != '\0')
	{
		*content = *addition;
		content++;
		addition++;
	}

	*content = '\0';
}

