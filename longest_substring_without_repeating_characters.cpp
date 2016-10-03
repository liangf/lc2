#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int result = 0;
		for (int i=0; i<s.length(); ++i) {
			int len = 0;
			unordered_map<char, int> umap;
			for (int j=i; j<s.length(); ++j) {
				if (umap.find(s[j]) == umap.end()) {
					++len;
					umap[ s[j] ] = j;
				}
				else {
					len = 0;
					umap.clear();
				}
				result = max(result, len);
			}
		}
		return result;
	}
};
*/

/*
// using unordered_map cannot pass????
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int i=0, result=0;
		while (i < s.length()) {
			int j = i;	
			unordered_map<char, int> umap;
			while (j<s.length() && umap.find(s[j])==umap.end())	{
				umap[ s[j] ] = j++;
			}
			result = max(result, j-i);
			i = j==s.length()? j : umap[ s[j] ]+1;
		}
		return result;
	}
};
*/

/*
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int result = 0, i = 0;	
		while (i < s.length()) {
			int j = i;
			vector<int> map(256, -1);
			while (j<s.length() && map[ s[j] ]<0) {
				map[ s[j] ] = j++;
			}
			result = max(result, j-i);	
			i = j==s.length() ? s.length() : map[ s[j] ]+1;
		}
		return result;
	}
};
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int left=0, right=0, result=0;
		//unordered_map<char, int> umap;
		unordered_set<char> uset;
		while (right < s.length()) {
			if (uset.find(s[right]) == uset.end()) {
				result = max(result, right-left+1);
				uset.insert(s[right++]);
			}
			else {
				uset.erase(s[left++]);
			}
		}
		return result;
	}
};

int main()
{
	string s = "abacd";
	
	Solution S;
	cout << S.lengthOfLongestSubstring(s) << endl;
}
