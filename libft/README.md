# LIBFT
#### My very first own library
<br/>
<br/>

## Summary
#### This project aims to code a C library regrouping usual functions that you'll be use for all your next projects.
<br/>
<br/>

## Introduction
#### C programming can be very tedious when one doesn’t have access to those highly useful standard functions. This project allows you to re-write those functions, understand them, and learn to use them. This library will help you with all your future C projects. Take the time to expand your libft throughout the year. But always, make sure to check which functions are allowed !

나의 첫 라이브러리를 만드는 프로젝트.  
앞으로 계속 쓰일 라이브러리인 만큼 최대한 신경써서 완벽히 만들어야 후에 문제가 발생하지 않을 수 있다.
<br/>
<br/>


## Install (Bonus included)
	$ make
<br/>
<br/>

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
