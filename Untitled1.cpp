#include<stdio.h>
#include<iostream>                        //headers
#include <string.h>
using namespace std;
struct bridge {               //structure bridge
 int north_waiting;
 int north_crossing;
 int north_consecutive;
 int south_waiting;
 int south_crossing;
 int south_consecutive;
 struct lock;
 struct northbound_done;
 struct southbound_done;
};
void bridge_init(struct bridge *b)  //function bridge_init having parameter as struct bridge
{
 b->north_waiting = 0;
 b->north_crossing = 0;;
 b->north_consecutive = 0;
 b->south_waiting = 0;
 b->south_crossing = 0;
 b->south_consecutive = 0;
 lock_init(&b->lock);
 cond_init(&b->northbound_done);
 cond_init(&b->southbound_done);
}
int bridge_arrive_north(struct bridge *b)   //functipn bridge arrive north having struct as a parameter
{
 lock_acquire(&b->lock);
 b->north_waiting++;
 while ((b->south_crossing > 0) ||
 ((b->south_waiting > 0) && (b->northConsecutive >= 5)) {
 cond_wait(&b->southbound_done, &b->lock);
 }
 b->north_waiting--;
 b->north_crossing++;
 b->northConsecutive++;
 b->southConsecutive = 0;
 lock_release(&b->lock);
}
int bridge_leave_north(struct bridge *b)     //functipn bridge leave north having struct as a parameter
{
 lock_acquire(&b->lock);
 b->north_crossing--;
 if (b->north_crossing == 0) {
 cond_broadcast(&b->northbound_done, &b->lock);
 }
 lock_release(&b->lock);
}
int bridge_arrive_south(struct bridge *b)   //functipn bridge arrive south having struct as a parameter
{
 lock_acquire(&b->lock);
 b->south_waiting++;
 while ((b->north_crossing > 0) ||
 ((b->north_waiting > 0) && (b->southConsecutive >= 5))) {
 cond_wait(&b->northbound_done, &b->lock);
 }
 b->south_waiting--;
 b->south_crossing++;
 b->southConsecutive++;
 b->northConsecutive = 0;
 lock_release(&b->lock);
}
int bridge_leave_south(struct bridge *b)  //functipn bridge leave south having struct as a parameter
{
 lock_acquire(&b->lock);
 b->south_crossing--;
 if (b->south_crossing == 0) {
 cond_broadcast(&b->southbound_done, &b->lock);
 }
 lock_release(&b->lock);
}
int main(){
	int b;
	struct bridge b1;        //object creation for the structure
	/*b1.bridge_init(bridge *b);
	b1.bridge_arrive_north(bridge *b);
	b1.bridge_leave_north(bridge *b);
	 b1.bridge_arrive_south(bridge *b);
	 b1.bridge_leave_south(bridge *b);
	 
	//lock_init(); */
    return 0;
}
