#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		int result = 0;	
		stack<int> stk;

		for (int i=0; i<tokens.size(); ++i) {
			if (tokens[i]=="+" || tokens[i]=="-" || 
				tokens[i]=="*" || tokens[i]=="/")	{
				int a = stk.top();
				stk.pop();
				int b = stk.top();
				stk.pop();
				if (tokens[i] == "+") stk.push(b+a);			
				if (tokens[i] == "-") stk.push(b-a);			
				if (tokens[i] == "*") stk.push(b*a);			
				if (tokens[i] == "/") stk.push(b/a);			
			}
			else {
				stk.push(atoi(tokens[i].c_str()));
			}		
		}
		return result = stk.empty() ? 0 : stk.top();
	}
};

int main()
{
	vector<string> tokens;
/*
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");
*/
	tokens.push_back("4");
	tokens.push_back("13");
	tokens.push_back("5");
	tokens.push_back("/");
	tokens.push_back("+");
	Solution s;
	cout << s.evalRPN(tokens) << endl;
}
