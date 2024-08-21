
- Task 2  

  - The `fflush()` function in C is used to flush (or clear) the output buffer of a stream. In this case, fflush(stdout) is called after the printf() statement to ensure that the output is immediately displayed on the console.

    By default, the output to the standard output stream (stdout) is buffered, which means that the data is stored in a buffer before being written to the console. This buffering improves performance by reducing the number of system calls required to write data. However, it also means that the output may not be immediately visible on the console.

    In some cases, you may want to ensure that the output is immediately displayed, especially when you need to see the output in real-time or when the program is performing time-sensitive operations. Calling fflush(stdout) forces the buffer to be flushed and the data to be immediately written to the console.  

  - Calculate [time_sleep](https://excalidraw.com/#json=_hVhYmcu4yEecUL2ojHui,1sKIf-1iFNONsVk8eQKULA)  <!--https://excalidraw.com/#json=V5UXJ4D-WuMzwEdWQQytR,JKFoLT5AOD8Z3Xp9_xbFOg  -->

  - [Add priority when creating thread](https://docs.oracle.com/cd/E19455-01/806-5257/attrib-16/index.html) and maybe [this too](https://stackoverflow.com/questions/27558768/setting-a-thread-priority-to-high-c)

  - [Good to look at hash table in self-learning Prac04](../prac04/HashTable_Sol.c)

- Task 3
  - [So... I can create more threads than cores?](https://www.reddit.com/r/cpp_questions/comments/snl23k/can_i_use_more_threads_in_my_program_than_the/)


- Task 7
  - Probably the best example of using threads in this prac, let's do this prior to Task 6.

- Task 6
  - [`pi.c` paralellisation visualised](https://docs.google.com/spreadsheets/d/1EE0PfpnYO5xm4ezuVSI7JqDVzVUSruqeMytdBpgAZGY/edit?usp=sharing)

