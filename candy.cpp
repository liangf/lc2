#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
	int candy(vector<int> &ratings) {
		int result = 0;
		vector<int> left(ratings.size(), 1);
		vector<int> right(ratings.size(), 1);

		for (int i=1; i<ratings.size(); ++i) {
			if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
		}
		for (int i=int(ratings.size())-2; i>=0; --i) {
			if (ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;
		}
		for (int i=0; i<ratings.size(); ++i) {
			result += max(left[i], right[i]);
		}
		return result;
	}
};
*/

class Solution {
public:
	int candy(vector<int> &ratings) {
		if (ratings.size() == 0) return 0;
		int result = 0;
		vector<int> left(ratings.size(), 1);
		vector<int> right(ratings.size(), 1);

		for (int i=1; i<ratings.size(); ++i) {
			if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
		}
		result += max(1, left.back());
		for (int i=int(ratings.size())-2; i>=0; --i) {
			if (ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;
			result += max(left[i], right[i]);
		}
		return result;
	}
};

int main()
{

}
