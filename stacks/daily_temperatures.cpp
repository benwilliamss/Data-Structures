#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
	public:
    	vector<int> dailyTemperatures(vector<int>& temperatures)
   	{
		int list_size = temperatures.size();
		 	
        	vector<int> stack;//values pushed onto here
		int day_count; //var to store amount of days till change
		int temp_being_evaluated;

		bool temp_change_flag;//boolean to denote temp change

		for(int i = 0; i< list_size; i++)
		{
			day_count =0;
			temp_change_flag = false;
			temp_being_evaluated= temperatures[i];//temp being evaluated

			for(int y = i+1; y < list_size ;y++)
			{
				day_count++;
				if(temp_being_evaluated < temperatures[y])
				{
					temp_change_flag = true;
					stack.push_back(day_count);
					break;	
				}	
				
			}
			if(!temp_change_flag) stack.push_back(0); 
		}
		return stack;
    	}
};

void print_stack(vector<int> &stack)
{	
	for(int &x: stack) printf("%d, ", x);
	printf("\n");
	
}	
int main()
{
	Solution solution_one;
	vector<int> answers;


	vector<int> test_one = {73,74,75,71,69,72,76,73};
       	answers = solution_one.dailyTemperatures(test_one);
	print_stack(answers);


	vector<int> test_two = {30,40,50,60};
	answers = solution_one.dailyTemperatures(test_two);
	print_stack(answers);

	vector<int> test_three ={30,60,90};
	answers = solution_one.dailyTemperatures(test_three);
	print_stack(answers);


		
}
