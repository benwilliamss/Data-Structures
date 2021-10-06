#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
	bool isValid(string s) {

		vector<char> stack;
		char current_char;
		//cout << "string: " << s<< endl;

		for (int i = 0; i < s.length(); i++)
		{
			current_char = s[i];
		
			if (current_char == '[' || current_char == '(' || current_char == '{') stack.push_back(current_char);
			else if (!stack.empty())
			{

				switch (current_char)
				{

					case ')':

						//printf("\npopped % c", stack.back());
						if (stack.back() != '(') return false;
						stack.pop_back();
						break;


					case '}':

						//printf("\npopped %c", stack.back());
						if (stack.back() != '{') return false;
						stack.pop_back();
						break;


					case ']':
						//("\npopped %c", stack.back());
						if (stack.back() != '[') return false;
						stack.pop_back();
						break;

					default:
						//printf("\npushing %c", current_char);
						return false;
					}

			}
			else return false;
		}
		return stack.empty();
	}
};
int main()
{
	Solution solution_one;
	//simple tests	
	
	printf("\n expected: True -> result: %s", solution_one.isValid("[({(())}[()])]") ? "true" : "false");
	printf("\n expected: False -> result: %s", solution_one.isValid("((") ? "true" : "false");
	printf("\n expected: True -> result: %s", solution_one.isValid("{({()[]})}") ? "true" : "false");
	printf("\n expected: True -> result: %s", solution_one.isValid("{}()[]") ? "true" : "false");
	printf("\n expected: False  -> result: %s", solution_one.isValid("{[}]") ? "true" : "false");
	printf("\n expected: False -> result: %s", solution_one.isValid("]{") ? "true" : "false");
	printf("\n expected: False -> result: %s", solution_one.isValid("]") ? "true" : "false");




}
