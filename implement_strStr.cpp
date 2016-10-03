#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/*
class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (haystack==NULL || needle==NULL) return -1;
		if (strlen(needle) == 0) return 0;

		for (int i=0; i<strlen(haystack); ++i) {
			int j = 0;
			while (j<strlen(needle) && i+j<strlen(haystack)) {
				if (needle[j] != haystack[i+j]) break;
				++j;
			}
			if (j == strlen(needle)) return i;
		}
		return -1;
	}
};
*/

/*
class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (haystack==NULL || needle==NULL) return -1;
		if (strlen(needle) == 0) return 0;

		for (int i=0; i<strlen(haystack); ++i) {
			// add this, accepted, dont know why
			if (i+strlen(needle)-1>strlen(haystack)-1) return -1;
			// add this, accepted, dont know why
			int j = 0;
			while (j<strlen(needle) && i+j<strlen(haystack)) {
				if (needle[j] != haystack[i+j]) break;
				++j;
			}
			if (j == strlen(needle)) return i;
		}
		return -1;
	}
};
*/

/*
class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (haystack==NULL || needle==NULL || strlen(haystack)<strlen(needle)) return -1;
		if (strlen(needle) == 0) return 0;

		for (int i=0; i<=strlen(haystack)-strlen(needle); ++i) {
			int j = 0;
			while (j<strlen(needle) && i+j<strlen(haystack)) {
				if (needle[j] != haystack[i+j]) break;
				++j;
			}
			if (j == strlen(needle)) return i;
		}
		return -1;
	}
};
*/


class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (haystack==NULL || needle==NULL || strlen(needle)>strlen(haystack)) return -1;
		if (strlen(needle) == 0) return 0;
cout << strlen(needle) << endl;
		int base = 29;
		long long hash_haystack=0, hash_needle=0;
		for (int i=0; i<strlen(needle); ++i) {
			hash_needle += (needle[i]-'a'+1)*pow(base, i);
			hash_haystack += (haystack[i]-'a'+1)*pow(base, i);
		}
cout << hash_needle << " " << endl;
		if (hash_haystack == hash_needle) return 0;	
		for (int i=strlen(needle); i<strlen(haystack); ++i) {
			hash_haystack = hash_haystack / base;
			hash_haystack += (haystack[i]-'a'+1)*pow(base, strlen(needle)-1);
			if (hash_haystack == hash_needle) return i-strlen(needle)+1;	
		}
		return -1;
	}
};


int main()
{
	//char haystack[1] = {'\0'};
	//char needle[1] = {'\0'};

	//char haystack[2] = {'a', '\0'};
	//char needle[2] = {'a', '\0'};

	
	//char haystack[12] = "mississippi";
	//char needle[3] = "ss"; 

	//char haystack[5] = "abcd";
	//char needle[4] = "bcd"; 

	//char haystack[] = "abbbbbaabbaabaabbbaaaaabbabbbabbbbbaababaabbaabbbbbababaababbbbaaabbbbabaabaaaabbbbabbbaabbbaabbaaabaabaaaaaaaa";
	//char needle[] = "abbbaababbbabbbabbbbbabaaaaaaabaabaabbbbaabab"; 

	char haystack[1] = "";
	char needle[2] = "a"; 

	Solution s;
	cout << s.strStr(haystack, needle) << endl;
cout << -2 % 7 << endl;
cout << (1<<31)-1 << endl;
}
