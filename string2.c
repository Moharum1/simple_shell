#include "main.h"

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}

	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0);
	}
	else
	{
		return (*str1 - *str2);
	}
}

