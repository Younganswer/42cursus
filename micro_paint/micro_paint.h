#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum e_bool {
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct _Rectangle {
	int				width;
	int				height;
	unsigned char	background_char;
	unsigned char	**board;
}	Rectangle;

typedef struct _Op {
	unsigned char	flag;
	float			x;
	float			y;
	float			width;
	float			height;
	unsigned char	c;
}	Op;


#endif