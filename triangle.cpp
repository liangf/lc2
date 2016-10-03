#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int sum=0, minsum=INT_MAX;
		dfs(triangle, 0, 0, sum, minsum);
		return minsum;
	}
	void dfs(vector<vector<int> > &triangle, int m, int n, int sum, int &minsum) {
		if (m == triangle.size()) {
			minsum = min(sum, minsum);
			return;
		}
		sum += triangle[m][n];	
		dfs(triangle, m+1, n, sum, minsum);
		dfs(triangle, m+1, n+1, sum, minsum);
	}
};
*/

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.size() == 0) return 0;
		int N=triangle.size(), min_sum=INT_MAX;

		for (int i=1; i<N; ++i) {
			triangle[i][0] += triangle[i-1][0];
			triangle[i][i] += triangle[i-1][i-1];
			for (int j=1; j<i; ++j) {
				int a = triangle[i][j]+triangle[i-1][j];
				int b = triangle[i][j]+triangle[i-1][j-1];
				triangle[i][j] = min(a, b);
			}
		}	
		for (int j=0; j<N; ++j) {
			min_sum = min(min_sum, triangle[N-1][j]);
		}
		return min_sum;
	}
};

int main()
{
	vector<vector<int> >triangle;
	vector<int> vec;
	vec.push_back(-1);	
	triangle.push_back(vec);
	vec.clear();

	vec.push_back(2);	
	vec.push_back(3);	
	triangle.push_back(vec);
	vec.clear();
		
	vec.push_back(1);	
	vec.push_back(-1);	
	vec.push_back(-3);	
	triangle.push_back(vec);
	vec.clear();
/*
	vector<vector<int> >triangle;
	vector<int> vec;
	vec.push_back(2);	
	triangle.push_back(vec);
	vec.clear();

	vec.push_back(3);	
	vec.push_back(4);	
	triangle.push_back(vec);
	vec.clear();
		
	vec.push_back(6);	
	vec.push_back(5);	
	vec.push_back(7);	
	triangle.push_back(vec);
	vec.clear();

	vec.push_back(4);	
	vec.push_back(1);	
	vec.push_back(8);	
	vec.push_back(3);	
	triangle.push_back(vec);
	vec.clear();
*/

	Solution s;
	cout << s.minimumTotal(triangle) << endl;
}
