#include "get_next_line_bonus.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (2 < argc)
		return 1;
	(void) argv;
	int fd = open("41_with_nl.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	return 0;
}
