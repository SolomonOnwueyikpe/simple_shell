#include "shell.h"

int _strlen(char *s);
int _strcmp(char *s1, char *s2);

/**
 *  _strlen - Returns the length of a string.
 * @s: String length to check.
 * Return: The Integer length of the string.
 */

int _strlen(char *s)
{
	int length = 0;

	if (!s)
		return (0);

	for (; *s != '\0'; s++)
		length++;
	return (length);
}

/**
 * _strcmp - Performs lexicographic comparison of two strings.
 * @s1: First string.
 * @s2: Second string.
 * Return: Negative if s1 < s2, positive if s1 > s2, 0 if s1 == s2.
 */

int _strcmp(char *s1, char *s2)
{
	for (; *s1 && *s2; s1++, s2++)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	return (*s1 - *s2);
}

/**
 * starts_with - Checks if `needle` starts with `haystack`.
 * @haystack: The String to search.
 * @needle: The substring to find.
 * Return: The Address of the next character of `haystack` or NULL.
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}
	return ((char *)haystack);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The buffer source.
 * Return: Pointer to the destination buffer.
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
