#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

/*
class Solution {
public:
	string minWindow(string S, string T) {
		unordered_map<char, int> umap;
		for (int i=0; i<T.length(); ++i) ++umap[ T[i] ];
		
		int left=0, right=0, st=-1, len=INT_MAX, count=0;
		while (right < S.length()) {
			if (umap.find(S[right]) == umap.end()) ++right;
			else {
				if (--umap[S[right]] >= 0) ++count;
				while (count == T.length()) {
					if (right-left+1 < len) {
						st = left;
						len = right-left+1;
					}
					if (umap.find(S[left]) == umap.end()) ++left;
					else {
						if (++umap[S[left]] > 0) --count;
						++left;
					}
				} 
				++right;
			}
		}
		return st==-1 ? "" : S.substr(st, len);
	}
};
*/

class Solution {
public:
	string minWindow(string S, string T) {
		unordered_map<char, int> umap;
		for (int i=0; i<T.length(); ++i) ++umap[ T[i] ];
		
		int left=0, st=-1, len=INT_MAX, count=0;
		for (int right=0; right<S.length(); ++right) {
			if (umap.find(S[right]) == umap.end()) continue;
			if (--umap[S[right]] >= 0) ++count;
			if (count == T.length()) {
				for (; left<=right; ++left) {
					if (umap.find(S[left]) == umap.end()) continue;
					if (right-left+1 < len) {
						st = left;
						len = right-left+1;
					}
					if (++umap[S[left]] > 0) {
						--count;
						++left;
						break;
					}	
				}
			} 
		}
		return st==-1 ? "" : S.substr(st, len);
	}
};

int main()
{
	string S = "ADOBECODEBANC";
	string T = "ABC";

	Solution s;
	cout << s.minWindow(S, T) << endl;
}
