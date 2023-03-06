# Starve-Free-Readers-Writers-Problem
The Readers-Writers problem is a classical problem of process synchronisation in computer science.
The problem deals with the shared memory data set and multiple processes, where each process can be classified in two types:

(i)  **Reader** - Reader processes will read the data

(ii) **Writer** - Writer processes will write(update) the data 

It involves the problem of synchronization as the constraint is that only one writer process can access the data set at a time ,i.e, no other processes(either reader or writer) can access the data set at that time. While multiple readers are allowed to access the data set at a time , but no writer is allowed to access the data set at that time.  


# Classical Solution
For readers writers problem there already exists classical solutions(that have been told in class) that ensures that the constraints for this problem(mentioned above) are satisfied. But the issue is that in those solutions either reader or writer starve. To rectify that problem, I have written a soltuion that will solve the given problem and none of the readers and writers will starve.

# Starve Free Solution

We are using the semaphore enter to ensure that nither reader nor writer are starved. It is done because by using enter we are ensuring that all readers and writers are being processed in the same order(like FIFO queue) as they are arrived and no one starves. While if enter was not used , it may have been possible that only one type of process (say reader) may have been processed continously and then the other type processes would have been starved(as we have seen in classical solution in classs).

The semaphore constraint is used to ensure that either only readers or only one writer is accessing the data(critical section). It is done by using additional help of variables readers_currently_reading and a_writer_is_waiting. If the constraint is 1 and readers_currently_reading is 0 and a_writer_is_waiting is 1 then the semaphore semaphore_for_writer is signaled and writer accesses its critical section. Otherwise readers are accessing their critical section.
