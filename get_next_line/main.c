#include "get_next_line_bonus.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (2 < argc)
		return 1;
	(void) argv;
	int fd = open("multiple_line_with_nl.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return 0;
}
