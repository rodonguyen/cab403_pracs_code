# CAB403 Pracs - Rodo

Each folder has a README file. Read that first to get some tips and additional info.

### Prac 07
- https://leetcode.com/problems/fibonacci-number/solutions/
- https://search.brave.com/search?q=dynamic+programming&source=desktop

### Prac08  
a1:
- 1 terminal runs the TCP server `./tcp <port number>`
- 1 terminal (acts as the client) runs `echo <your message> | nc localhost <port number>` to send message to the server

- Related links:
    - https://man7.org/linux/man-pages/man2/socket.2.html
    - https://man7.org/linux/man-pages/man3/sockaddr.3type.html
    - https://man7.org/linux/man-pages/man2/recvmsg.2.html

a2:
- 1 terminal runs the UDP server `./udp <port number>`
- 1 terminal (acts as the client) runs `nc -u localhost <port number>` and type your message followed by an Enter to send the message to the server. 

### Prac12:
#### A1:

A.

Sequentially:  
a) Processing a log file: Reading system or application logs from start to finish.  
b) Streaming a video or audio file: Playing media content from beginning to end.  
c) Reading a text file for natural language processing: Analyzing text data line by line.  
Randomly:  
a) Database management systems: Accessing specific records without reading the entire file.  
b) Virtual memory systems: Fetching memory pages as needed from disk.  
c) Digital audio workstations: Accessing specific segments of audio files for editing.  

B. 

a) Create a new group (e.g., `'fileaccessgroup'`)  
b) Add the 4,990 users to this group  
c) Set the file ownership to the appropriate user and group:
`chown owner:fileaccessgroup filename`  
d) Set the file permissions to allow group read (and possibly write) access:  
`chmod 750 filename` (read/write for owner, read for group, no access for others)

4 - read
2 - write
1 - execute
0 - no per


R-W-E
1 1 1 = 7  (Owner)
1 1 0 = 6  (Group Access)
0 0 1 = 1  (Public)



C.  
- Advantages of mandatory locks:

Stronger enforcement of access control
Prevention of conflicting access even if applications fail to check locks
Simplification of application logic as lock checking is handled by the system

- Disadvantages of mandatory locks:

Potential for deadlocks if not carefully managed
Possible performance overhead due to system-level lock checking
Less flexibility for applications to implement custom locking strategies

- Advantages of advisory locks:

Greater flexibility for applications to implement custom locking schemes
Potentially better performance as lock checking is done at the application level
Easier to implement in distributed systems

- Disadvantages of advisory locks:

Relies on all applications cooperating and checking locks properly
Potential for data corruption if an application fails to respect locks
Can lead to more complex application code to handle locking properly

#### A4
```
truncate -s 10M testing1.txt
ls -l testing1.txt # Check size
```