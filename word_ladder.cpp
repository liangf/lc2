#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		int level = 0;
		queue<string> curQ;
		curQ.push(start);
		dict.insert(start); dict.insert(end);
		dict.erase(start);
		while ( !curQ.empty() ) {
			++level;
			queue<string> newQ;
			while ( !curQ.empty() ) {
				string s = curQ.front();
				curQ.pop();
				if (s == end) return level;
				for (int i=0; i<s.length(); ++i) {
					string s2 = s;
					for (int c='a'; c<='z'; ++c) {
						s2[i] = c;
						if (dict.find(s2) != dict.end()) {
							newQ.push(s2);
							dict.erase(s2);
						}
					}
				}	
			}
			curQ = newQ;
		}
		return 0;
	} 
};

int main()
{
	unordered_set<string> dict={"hot", "dot", "dog", "lot", "log"};
	string start="hit", end="cog";
	
	Solution s;
	cout << s.ladderLength(start, end, dict);
}
