#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
		unordered_map<string, vector<string>> umap;
	
		for (int i=0; i<strs.size(); ++i) {
			string s = strs[i];
			sort(s.begin(), s.end());
			umap[s].push_back(strs[i]);
		}	
		for (auto it=umap.begin(); it!=umap.end(); ++it) {
			if (it->second.size() > 1) {
				for (int i=0; i<it->second.size(); ++i) {
					result.push_back((it->second)[i]);
				}
			}
		}
		return result;
	}
};


int main()
{

}
