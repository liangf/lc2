#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<int> four(4, -1);
		vector<vector<int> > result;
		sort(num.begin(), num.end());

		for (int i=0; i<num.size(); ++i) {
			for (int left=i+1; left<num.size(); ++left) {
				int mid = left + 1;	
				int right = num.size() - 1;
				while (mid < right) {
					int sum = num[i] + num[left] + num[mid] + num[right];
					if (sum > target) --right;
					else if (sum < target) ++ mid;
					else {
						four[0] = num[i];
						four[1] = num[left];
						four[2] = num[mid];
						four[3] = num[right];
						result.push_back(four);
						while (mid+1<=right && num[mid]==num[mid+1]) ++mid;
						++mid;
						while (right-1>=mid && num[right]==num[right-1]) --right;
						--right;
					}
				}
				while (left+1<num.size() && num[left]==num[left+1]) ++left;
			}
			while (i+1<num.size() && num[i]==num[i+1]) ++i;
		}
		return result;
	}
};
*/

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<int> four(4, -1);
		vector<vector<int> > result;
		unordered_set<string> visited;
		unordered_map<int, vector<pair<int, int> > > umap;

		for (int i=0; i<num.size(); ++i) {
			for (int j=i+1; j<num.size(); ++j) {
				umap[num[i]+num[j]].push_back(make_pair(i, j));		
				while (j+1<num.size() && num[j]==num[j+1]) ++j;
			}
			while (i+1<num.size() && num[i]==num[i+1]) ++i;
		}
/*
for (auto it=umap.begin(); it!=umap.end(); ++it) {
	cout << it->first << ":\n";
	vector<pair<int, int> > vec =it->second;
	for (int i=0; i<vec.size(); ++i) {
		cout << vec[i].first << " " << vec[i].second << endl;
	} 
}
*/
		for (auto it=umap.begin(); it!=umap.end(); ++it) {
			if (umap.find(target-it->first) == umap.end()) continue;
			vector<pair<int, int> > va = umap[it->first];
			vector<pair<int, int> > vb = umap[target-it->first];
			for (int i=0; i<va.size(); ++i) {
				vector<int> index4(4, -1);
				for (int j=0; j<vb.size(); ++j) {
					index4[0] = (va[i].first);
					index4[1] = (va[i].second);
					index4[2] = (vb[j].first);
					index4[3] = (vb[j].second);
					if ( !hasDuplicated(visited, index4) ) {
						for (int k=0; k<4; ++k) four[k] = num[ index4[k] ];
						result.push_back(four);
					}
				}	
			}
		}		
		return result;
	}
	bool hasDuplicated(unordered_set<string> &visited, vector<int> &index4) {
		string s = "";
		sort(index4.begin(), index4.end());
		s.push_back('0'+index4[0]);
		for (int i=1; i<4; ++i) {
			if (index4[i] == index4[i-1]) return true;
			s.push_back('0'+index4[i]);
		}
		sort(s.begin(), s.end());
		if (visited.find(s) != visited.end()) return true;
		visited.insert(s);
		return false;
	}
};

int main()
{
	vector<int> num;
/*
	num.push_back(1);
	num.push_back(0);
	num.push_back(-1);
	num.push_back(0);
	num.push_back(-2);
	num.push_back(2);
*/

	num.push_back(-3);
	num.push_back(-2);
	num.push_back(-1);
	num.push_back(0);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);

	Solution s;
	vector<vector<int> > res = s.fourSum(num, 0);
	for (int i=0; i<res.size(); ++i) {
		for (int j=0; j<res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
