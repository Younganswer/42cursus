# Push_swap
### Because Swap_push isn’t as natural
<br/><br/><br/>

## Summary
#### This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.
<br/><br/><br/>

## Install
	$ make
	$ make bonus //for checker
* make bonus rule includes make (all)
<br/><br/><br/>

## Usage
### For custom input
	$ ./push_swap [num1] [num2] [num3] [...]
* Arguments must be a list of integers
	-  You can do like this
		* `$ ./push_swap 10 9 8 7 6 5 4 3 2 1`
	-  or this
		* `$ ./push_swap "10 9" 2 1 "6 5 4 3" 8 7`
<br/>

### For random input
```
$ make run
$ make run ARGC=[number of input]
```
* make run rule includes make bonus
* Default argc = 100
* Instructions are stored in "output.txt"
* The number of the instructions is displayed on the terminal
<br/><br/><br/><br/>

## Result
Thanks to @o-reo for using this push_swap_visualizer
<br/>
https://github.com/o-reo/push_swap_visualizer
<br/>
https://user-images.githubusercontent.com/55086725/190156930-16f5c704-cc31-4507-b886-99a644466fee.mp4
