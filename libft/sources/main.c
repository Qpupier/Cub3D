#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		test;
	char	*line;

	fd = open("main.c", O_RDONLY);
	test = get_next_line(fd, &line);
	printf("%d | %s\n", test, line);
	free(line);
	test = get_next_line(-42, &line);
	printf("%d | %s\n", test, line);
	free(line);
	while ((test = get_next_line(fd, &line)))
	{
		printf("%d | %s\n", test, line);
		free(line);
	}
	printf("%d | %s\n", test, line);
	free(line);
	return (0);
}
