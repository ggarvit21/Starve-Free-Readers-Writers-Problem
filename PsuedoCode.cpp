
/*Semaphore Implementation*/

//implementing semaphore using struct
struct semaphore {
    int s=1;
    
    semaphore(){
      s=1;  // if no parameters are passed then the s is initialized as 1 (considering binary semaphore if no parameters are passed in the constructor) 
    }
    
    
    semaphore(int n){
      s=n;  // if an integer is passed in the constructor initialize that to n
    }
    
    queue<process> blocked_process; //this queue will contain all the processes that will get blocked
 
}

wait(semaphore Semaphore)
{
    if (Semaphore.s != 0) {
        Semaphore.s --; // if value of Semaphore is not 0 then decrease the value by 1 
    }
    else {
        blocked_process.push(process) sleep(); // if value of Semaphore is 0 then sleep the process and push it in the blocked_process queue
    }
}

signal(semaphore Semaphore)
{
    if (Semaphore.blocked_process.empty()) {
        Semaphore.s++; // if no process are being blocked then increase the value of Semaphore
    }
    else {
        Process to_be_woke = blocked_process.front(); // the front process of blocked_queue will be selected for waking up
        q.pop(); // remove this process from the queue
        wakeup(p);
    }
}
 


/*declaration of global variables*/

// Semaphores declared for accessing global variables
semaphore enter = new semaphore(1);  // semaphore for assigning equal priority to readers and writers(for starve free)  
semaphore constraint = new semaphore(1); // semaphore making sure that either only readers or only 1 writer are accessing data  
semaphore semaphore_for_writer = new semaphore(0); // semaphore telling writer to write
 
int readers_currently_reading = 0;  // this indicates the number of readers who are currently reading 
bool a_writer_is_waiting = false; // Indicates if a writer is waiting


/* code for reader */
while(1){

    // reader enters (Entry Section)
    enter.wait(process);
    readers_currently_reading++;
    enter.signal();

    
        // Code for Reader reading data(i.e. , reader's critical section)
     
    
    // Reader leaves (Exit Section)
    constraint.wait(processID);
    readers_currently_reading--;
    if(a_writer_is_waiting && readers_currently_reading == 0){
        semaphore_for_writer.signal();
    }
    constraint.signal();

    // Remainder section 

}


//writer
while(1){

    // Writer enters (Entry Section)
    enter.wait(processID);
    constraint.wait(processID);
    if(readers_currently_reading == 0){
        constraint.signal();
    }
    else{
        a_writer_is_waiting = true;
        constraint.signal();
        semaphore_for_writer.wait();
        a_writer_is_waiting = false;
    }

     
     // Code for Writer accesses data (i.e. , writer's critical section)
     


   // Writer leaves (Exit Section)
   enter.signal();

   // Remainder Section

} 
