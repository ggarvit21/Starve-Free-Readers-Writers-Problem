# Starve-Free-Readers-Writers-Problem
The Readers-Writers problem is a classical problem of process synchronisation in computer science.
The problem deals with the shared memory data set and multiple processes, where each process can be classified in two types:

(i)  **Reader** - Reader processes will read the data

(ii) **Writer** - Writer processes will write(update) the data 

It involves the problem of synchronization as the constraint is that only one writer process can access the data set at a time ,i.e, no other processes(either reader or writer) can access the data set at that time. While multiple readers are allowed to access the data set at a time , but no writer is allowed to access the data set at that time.  


# Classical Solution
For readers writers problem there already exists classical solutions(that have been already discussed in lecture) that ensures that the constraints for this problem(mentioned above) are satisfied. But the issue is that in those solutions either reader or writer starve. To rectify that problem, I have written a soltuion that will solve the given problem and none of the readers and writers will starve.

# Starve Free Solution

We are using the semaphore `enter` to ensure that niether reader nor writer are starved. It is done because by using `enter` we are ensuring that all readers and writers are being processed in the same order(like FIFO queue) as they are arrived and no one starves. While if `enter` was not used , it may have been possible that only one type of process (say reader) may have been processed continously and then the other type processes would have been starved(as we have seen in classical solution in classs).

The semaphore `semaphore_for_reader` is used to ensure that variable `readers_currently_reading` is modified by only one process at a time.

Constraint of the problem is satisifed by using additional help of variable `readers_currently_reading`. If `readers_currently_reading` is 0 then the semaphore `semaphore_for_writer` is signaled and writer accesses its critical section. Otherwise when `readers_currently_waiting` becomes 1 `semaphore_for_writer` it is waited and the readers are accessing their critical section. 

NOTE: `readers_currently_waiting` becoming 1  implies that some readers are accessing the data set and hence writer has to be waited. 
