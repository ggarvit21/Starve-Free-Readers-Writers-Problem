 # Semaphore Implementation
//implementing semaphore using struct
struct semaphore {
    int s=1;
    
    semaphore(){
      s=1;  // if no parameters are passed then the s is initialized as 1 (considering binary semaphore if no parameters are passed in the constructor) 
    }
    
    
    semaphore(int n){
      s=n;  // if there are n instances ( if an integer is passed in the constructor) 
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
 
