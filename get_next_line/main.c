#include "get_next_line_bonus.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (2 < argc)
		return 1;
	int fd = open(argv[1], O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	return 0;
}