#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char **argv)
{
	info_t shell_info = INFO_INIT;
	int input_fd = 2;

	if (argc == 2)
	{
		input_fd = open(argv[1], O_RDONLY);

		if (input_fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: Can't open ");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}

		shell_info.readfd = input_fd;
	}

	populate_env_list(&shell_info);
	read_history(&shell_info);
	hsh(&shell_info, argv);

	return (EXIT_SUCCESS);
}
