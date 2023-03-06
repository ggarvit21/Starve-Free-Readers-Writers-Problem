
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
Semaphore enter = new Semaphore(1);  // semaphore for assigning equal priority to readers and writers(for starve free)  
Semaphore semaphore_for_reader = new Semaphore(1); // semaphore for mutual exclusion of readers_currently_reading 
Semaphore semaphore_for_writer = new Semaphore(0); // semaphore telling writer to write
 
int readers_currently_reading = 0;  // this indicates the number of readers who are currently reading  

/* code for reader */
while(1){

    // reader enters (Entry Section)
    enter.wait(process);

    semaphore_for_reader.wait(process);
    readers_currently_reading++;
    if(readers_currently_reading==1){
        semaphore_for_writer.wait(process); //if number of readers become more than zero then writer will have to wait
    }
    semaphore_for_reader.signal();

    enter.signal();
    
        // Code for Reader reading data(i.e. , reader's critical section)
     
    
    // Reader leaves (Exit Section) 
    semaphore_for_reader.wait(process);
    readers_currently_reading--;
    if(readers_currently_reading == 0){
        semaphore_for_writer.signal();
    }
    semaphore_for_reader.signal();


}


//writer
while(1){

    // Writer enters (Entry Section)
    enter.wait(process);

    semaphore_for_writer.wait(process);

    enter.signal(); // since writer is entering its critical section it can signal the enter


     // Code for Writer accesses data (i.e. , writer's critical section)
     


   // Writer leaves (Exit Section)
   semaphore_for_writer.signal();


} 
