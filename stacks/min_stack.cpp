#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class MinStack {
	private:
		vector<int> stack;
		int size;

		

	public:
    		MinStack() 
		{
			this -> size =0;
    		}
    
    		void push(int val) 
		{
			stack.push_back(val);
			size++;
        
    		}
    
    		void pop() 
		{
			size--; 
        
    		}
    
    		int top() 
		{
			return stack[size-1];
        
    		}
    
    		int getMin() 
		{
			int min_value;
			for(auto curr: stack)
			{
				if(min_value > curr)
				{
					min_value = curr ;
				}
				
			}
			return min_value;
        
    		}
 		void operator delete(void *ptr)
        	{
            		cout << "memory freed from heap" << endl;
            		free(ptr);
        	}
};


int main()
{
	MinStack* stack = new MinStack(); //object created on heap

	/*stack -> push(5);
	printf("%d\n", stack -> top()); 
	stack -> push(32);
	printf("%d\n", stack -> top()); 
	stack -> pop();
	printf("%d\n", stack -> top()); 
	*/

	stack -> push(-2);
	stack -> push(-4);
	stack -> push(-74);
	stack -> push(89);
	stack -> push(85);
	stack -> push(86);
	stack -> push(87);


	printf("%d\n", stack -> getMin()); 

	delete stack;//manually releases 	

	return 0;
}
