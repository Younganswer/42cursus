# LIBFT
#### My very first own library
<br/><br/>

## Summary
#### This project aims to code a C library regrouping usual functions that you'll be use for all your next projects.
<br/><br/><br/>

## Introduction
#### C programming can be very tedious when one doesn’t have access to those highly useful standard functions. This project allows you to re-write those functions, understand them, and learn to use them. This library will help you with all your future C projects. Take the time to expand your libft throughout the year. But always, make sure to check which functions are allowed !
<br/>
This is a project to build my very first own library. <br/>
As it is a library that will continue to be used in the future, you must pay as much attention as possible to make it perfect so that problems may not occur in the future.
<br/><br/><br/><br/><br/>

## Install (Bonus included)
	$ make
<br/><br/><br/>

## Usage
	$ [CC] [CFLAGS] [your_main.c] libft.a -o main.out
+ Compile library file (libft.a) with your c files.
+ You need to include 'libft.h' header into your c or header files.
<br/>

Example
```
#include "libft.h"
#include <stdio.h>

int main(void) {
	char *str = "Hello World!";
	size_t str_len = ft_strlen(str);
	printf("%s\nlen: %zu\n", str, str_len);
	return (0);
}


>> ./main.out
Hello World!
len: 12
>> 
```
