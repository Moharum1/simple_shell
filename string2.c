#include "main.h"

int _strcmp(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 - *str2); // Return the difference of the first differing characters
        }
        str1++;
        str2++;
    }

    // Check for the end of both strings
    if (*str1 == '\0' && *str2 == '\0') {
        return 0; // Strings are equal
    } else {
        return (*str1 - *str2); // Return the difference if one string is a prefix of the other
    }
}
