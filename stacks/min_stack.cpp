#include <stdio.h>
#include <iostream>
#include <vector>


/*
 Constraints:

    -231 <= val <= 231 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

using namespace std;

class MinStack {
	private:
		vector<int> stack;
			

	public:
    		 
    		void push(int val) 
		{			
			stack.push_back(val);
			printf("pushed(%d)\n", val);

    		}
    
    		void pop() 
		{
			stack.pop_back();
    			printf("Pop!\n");

		}
    
    		int top() 
		{
			return stack.back();
        
    		}
    
    		int getMin() 
		{
			int min_value = stack.front();	
			for(auto& curr_value: stack)
			{	
				if(min_value> curr_value) min_value = curr_value;
							
			}
			return min_value;
        
    		}
 		void operator delete(void *ptr)
        	{
            		printf("\nmemory freed from heap");
            		free(ptr);
        	}
};


int main()
{
	MinStack* stack = new MinStack(); //object created on heap

	stack -> push(5);
	stack -> push(32);
	stack -> pop();
	stack -> push(-2);
	stack -> push(9);
	stack -> push(-3);

	printf("min value: %d\n", stack -> getMin()); 

	stack -> pop();
	
	printf("top of stack: %d\n", stack -> top());
	
	printf("min value: %d\n", stack -> getMin()); 

	delete stack;//manually releases 	

	return 0;
}
