#include "shell.h"

/**
 * bfree - frees memory and set pointer to NULL
 * @target_ptr: Address of Pointer to free and set to NULL
 *
 * Return: 1 if freed, otherwise 0.
 */

int bfree(void **target_ptr)
{
	if (target_ptr && *target_ptr)
	{
		free(*target_ptr);
		*target_ptr = NULL;
		return (1);
	}
	return (0);
}
