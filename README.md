# Starve-Free-Readers-Writers-Problem
The Readers-Writers problem is a classical problem of process synchronisation in computer science.
The problem deals with the shared memory data set and multiple process, where each process can be classified in two types:

(i)  **Reader** - Reader processes will read the data

(ii) **Writer** - Writer processes will write(update) the data 

It involves the problem of synchronization as the constraint is that only one writer process can access the data set at a time ,i.e, no other processes(either reader or writer) can access the data set at that time. While multiple readers are allowed to access the data set at a time , but no writer is allowed to access the data set at that time.  


# Classical Solution
For readers writers problem there already exists classical solutions that ensures that the constraints for this problem(mentioned above) are satisfied. But the problem is that in those solutions either reader or writer starve. To rectify that problem, i am proposing a solution that will solve the given problem and none of the readers and writers will starve.
