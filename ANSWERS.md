**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created - Initial state, as the name implies it was just made.
Ready - Process ready and waiting to be executed, loaded into memory.
Running - Process has been assigned to the processor and the code is ran.
Blocked - Process cannot be completed and is stopped.
Terminated - Process finished or was killed.

**2. What is a zombie process?**
A process that has been executed but stayed in the process table because it wasn't cleaned by the parent process.

**3. How does a zombie process get created? How does one get destroyed?**
A zombie process is created once a process has finished executing and a parents process is not there to clean it up. A reaper process can check if processes are running
and terminate them, a kill command or reboot can also destroy a zombie process.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
A compiled language has the benefit of faster performance for the computer. It will execute the processes quicker, hence why used for things like OSes often. Large, data heavy
applications would benefit from this.
