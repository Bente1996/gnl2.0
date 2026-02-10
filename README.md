𝑇ℎ𝑖𝑠 𝑝𝑟𝑜𝑗𝑒𝑐𝑡 ℎ𝑎𝑠 𝑏𝑒𝑒𝑛 𝑐𝑟𝑒𝑎𝑡𝑒𝑑 𝑎𝑠 𝑝𝑎𝑟𝑡 𝑜𝑓 𝑡ℎ𝑒 42 𝑐𝑢𝑟𝑟𝑖𝑐𝑢𝑙𝑢𝑚 𝑏𝑦 𝑏𝑒𝑑𝑒-𝑘𝑜𝑛.


Description:

The get_next_line project is about creating a function that reads a file, returning one line at a time on repeated function calls.

I stored the characters read by calling read() in a static buffer so that the contents of the buffer would be stored in between calls. 
This was necessary because depending on BUFFER_SIZE, the buffer could be filled with multiple and/or incomplete lines after reading in to it.

To clarify:

Read() doesn't allow you to jump back and forth in a file to start reading from there (after every read call an index moves to the last byte read).
If you call the get_next_line function a second time, read() will continue where it left of:
This makes it unavoidable to make use of a static variable to store the bytes that were previously read and not formed in to a complete line yet.


Instructions:

This is how you compile the project: cc -Wall -Wextra -Werror -D BUFFER_SIZE=[int] [C source files]


Resources:
- Man read().
- No AI was used.


Algorithm:

I didn't use an algorithm because that seemed redundant.
