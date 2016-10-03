#include <iostream>
#include <vector>
using namespace std;
/*
// Runtime Error
class Solution {
public:
	double pow(double x, int n) {
		if (n >= 0) return pow2(x, n);
		return 1.0/pow2(x, -n);
	}
	double pow2(double x, int n) {
		if (n == 0) return 1;	
	
		if (n%2 == 0) return pow2(x, n/2)*pow2(x, n/2);
		else return x*pow2(x, n-1);
	}
};
*/

/*
// Runtime Error
class Solution {
public:
	double pow(double x, int n) {
		if (n >= 0) return pow2(x, n);
		return 1.0/pow2(x, -n);
	}
	double pow2(double x, int n) {
		double d[n+1];
		d[0] = 1;
		for (int i=1; i<=n; ++i) {
			if (i%2 == 0) d[i] = d[i/2]*d[i/2];
			else d[i] = x * d[i-1];
		}	
		return d[n];
	}
};
*/

class Solution {
public:
	double pow(double x, int n) {
		double half = 0.0;
		if (n >= 0) return pow(x, n, half);
		return 1.0/pow(x, -n, half); 
	}
	double pow(double x, int n, double &half) {
		if (n == 0) return 1.0;	
		
		half = pow(x, n/2, half);
		if (n%2 == 0) half = half * half;
		else half = half * half * x;
		return half;
	}
};

int main()
{
	Solution s;
	cout << s.pow(2, -3);
}
