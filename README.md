# Project-cs316
You have been hired by Coltrans Limited to automate the flow of traffic on a one-lane bridge that has been the
site of numerous collisions. Coltrans Limited wants you to implement the following rules:
● Traffic can flow in only a single direction on the bridge at a time.
● Any number of cars can be on the bridge at the same time, as long as they are all traveling in the same
direction.
● To avoid starvation, you must implement the “five car rule”: once 5 or more consecutive northbound cars
have entered the bridge, if there are any southbound cars waiting then no more northbound cars may enter
the bridge until some southbound cars have crossed. A similar rule also applies once 5 or more consecutive
southbound cars have entered the bridge.
You must implement the traffic flow mechanism in C by defining a structure struct bridge, plus five functions
described below.
When a northbound car arrives at the bridge, it invokes the function:
bridge_arrive_north(struct bridge *b)
This function must not return until it is safe for the car to cross the bridge, according to the rules above. Once a
northbound car has finished crossing the bridge it will invoke the function:
bridge_leave_north(struct bridge *b)
Southbound cars will invoke analogous functions bridge_arrive_south and bridge_leave_south.
Use the next pages to write a declaration for struct bridge and the four functions above, plus the function bridge_init,
which will be invoked to initialize the bridge
You must write your solution in C using the functions for locks and condition variables:
lock_init (struct lock *lock)
lock_acquire(struct lock *lock)
lock_release(struct lock *lock)
cond_init(struct condition *cond)
cond_wait(struct condition *cond, struct lock *lock)
cond_signal(struct condition *cond, struct lock *lock)
cond_broadcast(struct condition *cond, struct lock *lock)
Use only these functions (e.g., no semaphores or other synchronization primitives).
You may not use more than one lock in each struct bridge.
Your solution must not use busy-waiting.
If your southbound functions are identical to the northbound functions except that north is replaced with south (and
vice versa) in all identifiers, then you can omit the southbound functions and just circle this bullet point.
