#include "shell.h"

char *_memset(char *s, char b, unsigned int n);

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);
}

/**
 * ffree - To free a string of strings
 * @pp: The string of strings
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;

	while (*pp)
	{
		free(*pp);
		pp++;
	}

	free(a);
}

/**
 * _realloc - Reallocate a memory block
 * @ptr: Pointer to the previously allocated memory
 * @old_size: Size of the old memory block.
 * @new_size: Size of the new memory block.
 * Return: Pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
    char *new_ptr;
    size_t i;

    if (!ptr)
        return (malloc(new_size));

    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }

    if (new_size == old_size)
        return (ptr);

    new_ptr = malloc(new_size);

    if (!new_ptr)
        return (NULL);

    i = 0;
    while (i < old_size && i < new_size)
    {
        new_ptr[i] = ((char *)ptr)[i];
        i++;
    }

    free(ptr);
    return (new_ptr);
}
