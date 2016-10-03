#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

/*
// their is bug, cannot print all paths.
class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		unordered_map<string, vector<vector<string>> > umap;
		queue<string> curQ;
		curQ.push(start);
		//dict.insert(start); dict.insert(end);
		dict.insert(end);
		umap[start] = vector<vector<string>>(1, vector<string>(1, start));
		while ( !curQ.empty() ) {
			queue<string> newQ;
			while ( !curQ.empty() ) {
				string s = curQ.front();
				curQ.pop();
				//dict.erase(s);
				cout << s << " ";
				for (int i=0; i<s.length(); ++i) {
					string s2 = s;
					for (char c='a'; c<='z'; ++c) {
						s2[i] = c;
						// checked if s2 is visited or not
						if (dict.find(s2) != dict.end()) {
							dict.erase(s2);
							newQ.push(s2);
							vector<vector<string>> vec = umap[s];
							for (int k=0; k<vec.size(); ++k) {
								cout << "s2:" << s2 << endl;
								vec[k].push_back(s2);
								umap[s2].push_back(vec[k]);
							}
						}
					}
				}
			}
			curQ = newQ;
			cout << endl;
		}
		return umap[end];
	}
};
*/

/*
class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		unordered_map<string, vector<vector<string>> > umap;
		unordered_set<string> curSet, newSet;
		dict.insert(start); dict.insert(end);
		curSet.insert(start);
		dict.erase(start);
		umap[start] = vector<vector<string>>(1, vector<string>(1, start));
		
		while ( !curSet.empty() ) {
			for (auto it=curSet.begin(); it!=curSet.end(); ++it) {
				string s = *it;
				for (int i=0; i<s.length(); ++i) {
					string s2 = s;
					for (char c='a'; c<='z'; ++c) {
						s2[i] = c;
						if (dict.find(s2) != dict.end()) {
							newSet.insert(s2);
							dict.erase(s2);
						}
					}
				}
			}
			for (auto it=curSet.begin(); it!=curSet.end(); ++it) {
				string s = *it;
				for (int i=0; i<s.length(); ++i) {
					string s2 = s;
					for (char c='a'; c<='z'; ++c) {
						s2[i] = c;
						if (newSet.find(s2) != newSet.end()) {
							vector<vector<string>> vec = umap[s];
							for (int j=0; j<vec.size(); ++j) {
								vec[j].push_back(s2);
								umap[s2].push_back(vec[j]);
							}
						}
					}
				}
			}
			curSet = newSet;
			newSet.clear();
		}
		return umap[end];
	}
};
*/
/*
class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		unordered_map<string, vector<vector<string>> > umap;
		unordered_set<string> curSet, newSet;
		dict.insert(start); dict.insert(end);
		curSet.insert(start);
		dict.erase(start);
		umap[start] = vector<vector<string>>(1, vector<string>(1, start));
		
		while ( !curSet.empty() ) {
			for (auto it=curSet.begin(); it!=curSet.end(); ++it) {
				string s = *it;
				for (int i=0; i<s.length(); ++i) {
					string s2 = s;
					for (char c='a'; c<='z'; ++c) {
						s2[i] = c;
						if (dict.find(s2)!=dict.end() || newSet.find(s2)!=newSet.end()) {
							newSet.insert(s2);
							dict.erase(s2);
							vector<vector<string>> vec = umap[s];
							for (int j=0; j<vec.size(); ++j) {
								vec[j].push_back(s2);
								umap[s2].push_back(vec[j]);
							}
						}
					}
				}
			}
			curSet = newSet;
			newSet.clear();
		}
		return umap[end];
	}
};
*/

class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		unordered_map<string, vector<vector<string>> > umap;
		dict.insert(start); dict.insert(end);
		stack<string> stk;
		stk.push(start);	
		dict.erase(start);
		umap[start] = vector<vector<string>>(1, vector<string>(1, start));
		
		while ( !stk.empty() ) {
				string s = stk.top;
				stk.pop();
				for (int i=0; i<s.length(); ++i) {
					string s2 = s;
					for (char c='a'; c<='z'; ++c) {
						s2[i] = c;
						if (umap.find(s2))
						if (dict.find(s2)!=dict.end() || umap.find(s)) {
							stk.push(s2);
							dict.erase(s2);
							vector<vector<string>> vec = umap[s];
							for (int j=0; j<vec.size(); ++j) {
								vec[j].push_back(s2);
								umap[s2].push_back(vec[j]);
							}
						}
					}
				}
		}
		return umap[end];
	}
};

int main()
{
	unordered_set<string> dict={"hot", "dot", "dog", "lot", "log"};
	string start="hit", end="cog";
	
	Solution s;
	vector<vector<string>> res = s.findLadders(start, end, dict);
	cout << endl;
	for (int i=0; i<res.size(); ++i) {
		for (int j=0; j<res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
