#include <iostream>
#include <stdio.h>


using namespace std;

class Solution {
    
    public:
    bool isValid(string s) 
    {
         	
 	 
	 if(s.length() % 2 !=0)
	 { 
		 printf("Odd amount of brackets");
		 return false; //odd amount of brackets, always false
	 }
		
	 char popped_char;
	 char front_char = s.front();
	

	 //pop char, compare if the corresponding bracket is either next or at the front
	 while(!s.empty())
	 {	
	 	cout << "\n\n Current string: " <<  s << "\n" << endl;

		 popped_char = s.back(); //get back element 
		 s.pop_back(); //remove back element
		 printf("popped_char %c\n", popped_char);
			
		 switch(popped_char)
		 {
				
				case ')':
					if(s.back() == '(')
					{
						s.pop_back();//paired elements now removed
						break;
					}
					
					else if(front_char== '(')
					{	
						printf("popped %c Matches front %c", popped_char, front_char);
						//remove front element pair
						s.erase(0,1);
						front_char= s.front();
						break;
					}

			       		return false; //no matching elements 



				case ']': 
					if(s.back() == '[')
					{
						s.pop_back();//paired elements now removed
						break;
					}

					else if(front_char== '[')
					{	printf("popped: %c Matches front: %c", popped_char, front_char);
						//remove front element pair
						s.erase(0,1);
						front_char= s.front();
						break;
					}

					return false;


				case '}':
					if(s.back() == '{')
					{
						s.pop_back();//paired elements now removed
						break;
					}

					else if(front_char== '{')
					{
						printf("popped: %c Matches front: %c", popped_char, front_char);
						//remove front element pair
						s.erase(0,1);
						front_char= s.front();
						break;
					}

			       		return false; 

							
		 }

	 }
	 return true; //string now empty as all brackets now have respective counterparts
	} 
  
};


int main()
{
	Solution solution_one;
	//printf("\nstring valid: %s", solution_one.isValid("{[]}") ? "true" : "false");
	//	printf("\nstring valid: %s", solution_one.isValid("[(]") ? "true" : "false");
	//	printf("\nstring valid: %s", solution_one.isValid("}[(){]") ? "true" : "false");
	///printf("\n string valid: %s", solution_one.isValid("{}()[]") ? "true" : "false");
	printf("\nstring valid: %s", solution_one.isValid("[[]{}}") ? "true" : "false");



}
