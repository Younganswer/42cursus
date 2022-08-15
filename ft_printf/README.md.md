# FT_PRINTF
#### Because ft_putnbr() and ft_putstr() aren't enough
## Summary
+ The goal of this project is pretty straightfoward. You will recode printf(). You will mainly learn about using a variable number of arguments.
+ You will discover **variadic functions** in C.

## Install
	$ make

## Usage
	$ [CC] [CFLAGS] [your_main.c] libftprintf.a -o main.out
+ Compile library file (libftprintf.a) with your c files.
+ You need to include 'ft_printf.h' header into your c or header files.

Prototype
```
int ft_printf(const char *str, ...);
```

Example
```
ft_printf("Hello World!\nMy name is %s.\n", my_name);
>> Hello World!
>> My name is younhwan.
```
