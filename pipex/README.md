# Pipex
<br/>

## Summary
#### This project will let you discover in detail a UNIX mechanism that you already know by using it in your program.
<br/><br/><br/><br/>

## Install (Bonus included)
	$ make
<br/><br/><br/>

## Usage
	$ ./pipex file_in [cmd1] [cmd2] [...] file_out
	$ ./pipex "here_doc" LIMITER [cmd1] [cmd2] [...] file_out
<br/>

##### Example
```
$ ./pipex /etc/passwd "grep -v #" "cut -d : -f 5" "sort" output.txt
```
Should behave like:
```
$ < /etc/passwd grep -v '#' | cut -d : -f 5 | sort > output.txt
```

<br/><br/>