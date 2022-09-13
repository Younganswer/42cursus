# Push_swap
### Because Swap_push isn’t as natural
<br/>

## Summary
#### This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.
<br/><br/><br/>

## Install
	$ make
	$ make bonus //for checker
<br/><br/><br/>

## Usage
#### For custom input
	$ ./push_swap [num1] [num2] [num3] [...]
* Arguments must be a list of integers
	-  You can do like this
		* `$ ./push_swap 10 9 8 7 6 5 4 3 2 1`
	-  or this
		* `$ ./push_swap "10 9" 2 1 "6 5 4 3" 8 7`
<br/>

#### For random input
```
$ make run
$ make run ARGC=[number of input]
```
* Default argc = 100
* Commands will be saved in output.txt
* The number of the commands is displayed on the terminal