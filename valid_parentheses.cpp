#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for (int i=0; i<s.length(); ++i) {
			if (s[i]=='(' || s[i]=='[' || s[i]=='{') stk.push(s[i]);
			else {
				if ( stk.empty() ) return false;
				if (s[i]==')' && stk.top()=='(') stk.pop();
				else if (s[i]==']' && stk.top()=='[') stk.pop();
				else if (s[i]=='}' && stk.top()=='{') stk.pop();
				else return false;
			}
		}
		return stk.empty();
	}
};


int main()
{

}
