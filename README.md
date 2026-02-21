*This project has been created as part of the 42 curriculum by bede-kon.*


# Description:

The get_next_line project is about creating a function that reads a file, returning one line at a time on repeated function calls.

I stored the characters read by calling `read()` in a static buffer so that the contents of the buffer would be stored in between calls. 
This was necessary because depending on `BUFFER_SIZE`, the buffer could be filled with multiple and/or incomplete lines after reading in to it.

To clarify:

`Read()` doesn't allow you to jump back and forth in a file to start reading from there (after every read call an index moves to the last byte read).
If you call the `get_next_line` function a second time, `read()` will continue where it left of:
This makes it unavoidable to make use of a static variable to store the bytes that were previously read and not formed in to a complete line yet.


# Instructions:

This is how you compile the project:
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=[int] [C source files]
```


# Resources:
- Man 3 read.
- No AI was used.
- [MatsGPT](profile.intra.42.fr/users/mde-beer) (README: Algorithm, Formatting)


# Algorithm:

I read BUFFER_SIZE sized chunks of the file at a time, check if theres a
newline, and if there isnt, keep reading. While doing this, i glue the chunks
together. When i reach a newline, i split the chunk into the stuff with the
first newline, and the stuff after it. I store the stuff after the first
newline, and return the stuff before the newline, including the newline itself.
this is an algorithm. I guess.
