## Chapter 1


### Compilation

**1) Give an example of a feature common in interpreted languages that is rare in compiled languages.**

Dynamically typed variables.

**2) Name two advantages of static typing over dynamic typing.**

A programmer can tell the type of each variable by looking at the program and there will likely be less errors at run-time.

**3) Give an example of a static semantic error.**

A variable of type int being passed into a function that expects a char.

**4) What are two reasons you might want to turn off code optimization?**

Optimization makes code take longer to compile and sometimes reveals weird bugs that weren't present when optimization was off.

**5) When you run `gcc` with `-S`, why might the results look different on different computers?**

Different systems have different architectures.

**6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?**

The linker will report an incorrect function name.

**7) What is a segmentation fault?**

The error that occurs when attempting to read or write to an incorrect memory location.


## Chapter 2


### Processes

**1) Give a real-world example of virtualization (ideally not one of the ones in the book).**

A VPN makes it feel like your internet connection is directly in a different location.

**2) What is the difference between a program and a process?**

A process is an object that represents a running program.

**3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?**

To isolate running programs to make things easier to understand for programmers. It creates the illusion that everything is neatly ordered and less intertwined.

**4) What is the kernel?**

The portion of the operating system that creates threads, interfaces software to hardware, and other core responsibilities.

**5) What is a daemon?**

A process that runs in the background and provides operating system services.
 

## Chapter 3


### Virtual memory

**1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?**

5 bits gives you 32 options, so 6 bits are required.

**2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?**

2^32 or 4,294,967,296 characters.

**3) What is the difference between "memory" and "storage" as defined in Think OS?**

Memory is lost with power (volatile) storage is not (non-volatile).

**4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?**

GiB: gibibyte, 2^30 or 1,073,741,824 bytes. GB: gigabyte, 10^9 or 1,000,000,000 bytes. GiB/GB is 1.07.

**5) How does the virtual memory system help isolate processes from each other?**

Virtual memory makes it such that one process cannot generate a virtual address of memory for another process._

**6) Why do you think the stack and the heap are usually located at opposite ends of the address space?**

If the stack was right on top of the heap, then every time the heap grew, each element in the stack would have to be displaced by the size of the new element in the heap.

**7) What Python data structure would you use to represent a sparse array?**

A dictionary.

**8) What is a context switch?**

When the OS interrupts a process, saves the process' state, and then switches to running another process.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.
  
**1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).**

0x1332010 and 0x13320a0. Grows up.

**2) Add a function that prints the address of a local variable, and check whether the stack grows down.**

0x7ffef79e2bdc and 0x7ffef79e2bd8. Grows down.

**3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.**

The amount of space between them is the size of the allocated chunks. In my case, 20.

## Chapter 4


### Files and file systems

**1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.**

That a name of a file maps to its contents. Files are byte-based, while the storage they live in is block-based. A file system abstracts this such that a programmer doesn't have to worry about the transformation from byte to block.

**2) What information do you imagine is stored in an `OpenFileTableEntry`?**

The contents of an opened file and how much of the file has been read.

**3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?**

By interrupting the process, completing other tasks, and returning when the data has arrived Also, block transfers, prefetching, buffering, and caching.

**4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the file you wrote is not there.  What happened?**

That file could have been written into main memory (but not yet written to disk), which is volatile and becomes lost if power is cut. Writes to disk normally only happen when there is at least one block of data to write.

**5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?**

Inode can only hold 8 TiB of metadata. We need more!.

**6) What is overhead?  What is fragmentation?**

Overhead is the space not used by actual data (such as space used by the allocator). Fragmentation is the space not used by blocks.

**7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?**

Treating everything as a file, or a stream of bytes, allows programs to become more versatile. If a program can accept file input, it can also accept other input sources such as the piped output of another program.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

**1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?**

8 bit 128: 10000000
16 bit 128: 00000000 10000000
With accidental sign extension: 11111111 10000000

**2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.**

12:  01100
-12: 11100

Two's complement of 01100 = 01100 ^ 10000

**3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?**

Maybe biased integers are faster to create and compare to other numbers?

**4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?**

If a single precision IEEE float of value -13.0 was accidentally interpretted as an int, then its value would be perceived as -1051721728.

**5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.**

`letter ^= 32;`

## Chapter 6


### Memory management

**1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?**

Constant time: malloc, free

Linear time: calloc, realloc

**2) For each of the following memory errors, give an example of something that might go wrong:**

**a) Reading from unallocated memory.**

The value read could be nonsensical.

**b) Writing to unallocated memory.**

Something important could be overwritten.

**c) Reading from a freed chunk.**

The value read could be nonsensical.

**d) Writing to a freed chunk.**

Something important could be overwritten.

**e) Failing to free a chunk that is no longer needed.**

If enough unneeded chunks are not freed, then they could build up until you run out of memory to allocate. At that point, any additional calls to malloc will return NULL.

**3) Run**

    ps aux --sort rss

**to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?**

Of the top 20 processes using the most memory, 17 of them are Google Chrome.

**4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?**

The minimum chunk size that malloc can allocate on most systems is 16 bytes. Thus, allocating a large number of small chunks would be very space inefficient. This problem could be solved by using arrays to allocate the structures.

**If you want to know more about how malloc works, read [Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html).**



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?


 
## Chapter 11


### Semaphores in C
