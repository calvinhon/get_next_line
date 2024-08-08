#include "get_next_line.h"

int	main()
{
	char *line;
	int fd1, fd2, fd3, i;
	fd1 = open("fd1.txt", O_RDONLY);
	fd2 = open("fd2.txt", O_RDONLY);
	fd3 = open("fd3.txt", O_RDONLY);
	i = 0;
	while (i < 1)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		// line = get_next_line(fd2);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}