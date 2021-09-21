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
    ~MyCircularQueue(){
	printf("\nAllocated heap memory freed");
	free(array_ptr);	
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
	    if(head+1==size) head =0; 
	    else head++;

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


	printf("Test Case 1\n");
	
	printf("enqueue 1 - Expected: True... Result: %s \n", myCircularQueue.enQueue(1) ? "true" : "false"); 
	printf("enqueue 2 - Expected: True... Result: %s \n", myCircularQueue.enQueue(2) ? "true" : "false"); 
	printf("enqueue 3 - Expected: True... Result: %s \n", myCircularQueue.enQueue(3) ? "true" : "false"); 
	printf("enqueue 4 -Expected: False... Result: %s \n", myCircularQueue.enQueue(4) ? "true" : "false"); 
	
	printf("Queue.rear() - Expected: 3... Result: %d\n", myCircularQueue.Rear()); 
	
	printf("full - Expected: True... Result: %s\n", myCircularQueue.isFull() ? "true" : "false"); 
	printf("dequeue - Expected: True... Result: %s\n", myCircularQueue.deQueue() ? "true" : "false");  
	printf("enqueue - Expected: True... Result: %s\n", myCircularQueue.enQueue(4) ? "true" : "false"); 
	printf("Queue.rear() -  Expected: 4... Result: %d\n", myCircularQueue.Rear());     // return 4
	
	return 0;
	

		
};
