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
	 char char_to_look_for; 
	 bool respective_bracket_not_found;//stops checking anymore for matches when this flag is true
	

	 //pop char, compare if the corresponding bracket is either next or at the front
	 while(!s.empty())
	 {	
		 
		 respective_bracket_not_found=true;

	 	 //cout << "\n\n Current string: " <<  s << "\n" << endl;

		 popped_char = s.back(); //get back element 
		 s.pop_back(); //remove back element 
		 //printf("popped_char %c\n", popped_char);


			
		 switch(popped_char)
		 {
				
				case ')':
					char_to_look_for = '('; 
					break;

				case ']': 
					char_to_look_for = '[';
					break;

				case '}':
					char_to_look_for = '{'; 
					break;
				default:
					//hit a left bracket
					//which already should be removed by this point
					//string not valid
					return false;			
							
		 }
		 
		 for(int i= (s.length()-1); i>=0; i--){
					 	
		 	if(s[i] == char_to_look_for)
			{	
				respective_bracket_not_found = false; 
				s.erase(i,1); //remove element, not considered again
				break;
			}
		 } 
		if(respective_bracket_not_found) return false;

	 }
	 return true; //string now empty as all brackets now have respective counterparts
	} 
  
};


int main()
{
	Solution solution_one;
	
	
	//printf("\nstring valid: %s", solution_one.isValid("[({(())}[()])]") ? "true" : "false");
	//printf("\nstring valid: %s", solution_one.isValid("((") ? "true" : "false");
	//printf("\nstring valid: %s", solution_one.isValid("{({()[]})}") ? "true" : "false");
	//printf("\n string valid: %s", solution_one.isValid("{}()[]") ? "true" : "false");
	//printf("\nstring valid: %s", solution_one.isValid("[[]{}}") ? "true" : "false");



}
