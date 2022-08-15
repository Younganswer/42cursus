# get_next_line
#### Reading a line from a fd is way too tedious
<br/>
<br/>

## Summary
#### This project is about programming a function that returns a line read from a file descriptor.
<br/>
<br/>

## Goals
#### This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: static variables.
<br/>
<br/>

## Usage (Bonus included)
	$ [CC] [CFLAGS] [your_main.c] get_next_line.c get_next_line_utils.c -o main.out
+ You need to include 'get_next_line.h' header into your c or header files.
<br/>

Prototype
```
char *get_next_line(int fd);
```
<br/>

Example
```
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void) {
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	return (0);
}

------------------------ test.txt ------------------------
Hello World!

----------------------------------------------------------

>> ./main.out
Hello World!
>> 
```
