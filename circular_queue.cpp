#include <stdio.h>
#include <iostream>
class MyCircularQueue {
private:
	int tail = 0;
	int head = 0;
	int size;
	int * array_ptr;
	int counter =0;
		       	
public:
    MyCircularQueue(int k) {
        
        array_ptr = (int*)malloc(sizeof(int)*k); 
	size=k;
       	
		
    }
    
    bool enQueue(int value) {
        if(isFull())
	{
		return false;
	}

	if(tail==size) //
	{
		tail = 0;
	       	array_ptr[tail] = value;	
	}
	else {
		array_ptr[tail] = value;
		
	};
	
	tail++;
	counter++;	
	return true;
    }
    
    bool deQueue() {
	    if (isEmpty())
	    {	
		    return false;
	    		
	    }
	    head++;
	    counter--;
	    return true;
		//return false if empty 
		//true if not
	    
        	
    }
    
    int Front() {
	    if(isEmpty()){
	    	return -1;
	    }
	    return array_ptr[head];
        
    }
    
    int Rear() {
	   
	    if(isEmpty()){
	    	return -1;
	    }
	    
	    return array_ptr[tail-1];
    }
    
    bool isEmpty() {
        return counter == 0;     
        
    }
    
    bool isFull() {
	    return counter == size;
        
    }
};


int main()
{
	MyCircularQueue myCircularQueue =  MyCircularQueue(3);
	printf("enqueue 1 - %s \n", myCircularQueue.enQueue(1) ? "true" : "false"); // return True
	printf("enqueue 2 - %s \n", myCircularQueue.enQueue(2) ? "true" : "false"); // return True
	printf("enqueue 3 - %s \n", myCircularQueue.enQueue(3) ? "true" : "false"); // return True
	printf("enqueue 4 - %s \n", myCircularQueue.enQueue(4) ? "true" : "false"); // return False
	
	printf("rear: %d\n", myCircularQueue.Rear()); // return 3
	
	printf("full - %s\n", myCircularQueue.isFull() ? "true" : "false"); // return True
	printf("dequeue - %s\n", myCircularQueue.deQueue() ? "true" : "false");  // return True
	printf("enqueue - %s\n", myCircularQueue.enQueue(4) ? "true" : "false"); // return True
	printf("rear: %d\n", myCircularQueue.Rear());     // return 4

	return 0;
	

		
};
