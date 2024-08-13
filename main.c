#include "get_next_line.h"

int	main()
{
	// char *line1, *line2, *line3, *line4;
	int fd1, fd2, fd3;
	// int fd4;
	char *line;
	int i = 0;
	fd1 = open("fd1.txt", O_RDONLY);
	fd2 = open("fd2.txt", O_RDONLY);
	fd3 = open("fd3.txt", O_RDONLY);
	// fd4 = open("a.out", O_RDONLY);
	while (++i < 10)
	{
		line = get_next_line(fd1);
		printf("fd1: %s", line);
		free (line);
		line = get_next_line(fd2);
		printf("fd2: %s", line);
		free (line);
		line = get_next_line(fd3);
		printf("fd3: %s", line);
		free (line);
		// line = get_next_line(fd4);
		// printf("fd4: %s", line);
		// free (line);
	}
	// line1 = get_next_line(fd1);
	// while (line1)
	// {
	// 	printf("fd1: %s", line1);
	// 	free(line1);
	// 	line1 = get_next_line(fd1);
	// }
	// free(line1);
	// printf("\n");
	// printf("\n");
	// line2 = get_next_line(fd2);
	// while (line2)
	// {
	// 	printf("fd2: %s", line2);
	// 	free(line2);
	// 	line2 = get_next_line(fd2);
	// }
	// free(line2);
	// printf("\n");
	// printf("\n");
	// line3 = get_next_line(fd3);
	// while (line3)
	// {
	// 	printf("fd3: %s", line3);
	// 	free(line3);
	// 	line3 = get_next_line(fd3);
	// }
	// free(line3);
	// printf("\n");
	// printf("\n");
	// line4 = get_next_line(fd4);
	// while (line4)
	// {
	// 	printf("fd3: %s", line4);
	// 	free(line4);
	// 	line4 = get_next_line(fd4);
	// }
	// free(line4);
	// printf("\n");
	close(fd1);
	close(fd2);
	close(fd3);
	// close(fd4);
	return (0);
}