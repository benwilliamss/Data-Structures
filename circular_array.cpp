#include <stdio.h>
#include <iostream>
class MyCircularQueue {
private:
	int tail=0;
	int head =0;
	int size;
		       	
public:
    MyCircularQueue(int k) {
        
        int Queue[k];
	size=k; 
    }
    
    bool enQueue(int value) {
        if(Queue.isFull())
	{
		return false;
	}

	if(tail +1 >=size)
	{
		tail = 0;
	       	Queue[tail] = value;	
	}
	else Queue[tail++] = value;
	
	return true;
    }
    
    bool deQueue() {
	    if (Queue.isEmpty())
	    {
		    return false;
	    		
	    }
	    head++;
	    return true;
		//return false if empty 
		//true if not
	    
        	
    }
    
    int Front() {
	    if(Queue.isEmpty()){
	    	return -1;
	    }
	    return queue[head];
        
    }
    
    int Rear() {
	   
	    if(Queue.isEmpty()){
	    	return -1;
	    }

	    return Queue[tail];
    }
    
    bool isEmpty() {
        return head == tail;     
        
    }
    
    bool isFull() {
	    if (head + tail+1 == size || head-1 ==tail) return true;
        
    }
};


int main()
{
	MyCircularQueue myCircularQueue = new MyCircularQueue(3);
	/*printf("enqueue 1 - %s", myCircularQueue.enQueue(1) ? "true" : "false"); // return True
	printf("enqueue 2 - %s", myCircularQueue.enQueue(2) ? "true" : "false"); // return True
	printf("enqueue 3 - %s", myCircularQueue.enQueue(3) ? "true" : "false"); // return True
	printf("enqueue 4 - %s", myCircularQueue.enQueue(4) ? "true" : "false"); // return False
	printf("rear: %d", myCircularQueue.Rear());                              // return 3
	printf("full - %s", myCircularQueue.isFull());                          // return True
	printf("dequeue - %s", myCircularQueue.deQueue() ? "true" : "false");  // return True
	printf("enqueue - %s", myCircularQueue.enQueue(4) ? "true" : "false"); // return True
	printf("rear: %d", myCircularQueue.Rear());     // return 4
	*/	
}
