#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> vec, result;
		for (int i=0; i<words.size(); ) {
			if (canAddWord(vec, words[i], L)) {
				vec.push_back(words[i]);
				++i;
			}
			else {
				result.push_back(getLine(vec, L));
				vec.clear();
			}
		}
		if (vec.size() > 0) {
			string lastline = "";
			for (int i=0; i<vec.size()-1; ++i) lastline += vec[i] + " ";
			lastline += vec.back();
			lastline.resize(L, ' ');
			result.push_back(lastline);
		}
		return result;
	}
	bool canAddWord(vector<string> &vec, string word, int L) {
		int len = vec.size();
		for (int i=0; i<vec.size(); ++i) len += vec[i].length();
		len += word.length();
		return len <= L;
	}
	string getLine(vector<string> &vec, int L) {
		string line = "";
		if (vec.size() == 1) {
			line += vec[0];
			line.resize(L, ' ');
			return line;
		}
		int len=0, extra=0, average=0;
		for (int j=0; j<vec.size(); ++j) len += vec[j].length();

		average = (L-len) / (vec.size()-1);
		extra = (L-len) % (vec.size()-1);
		for (int j=0; j<vec.size()-1; ++j) {
			line += vec[j] + string(average, ' ');
			if (extra-- > 0) line += " ";
		}
		line += vec.back();	
		return line;
	}
};

int main()
{
	Solution s;
	vector<string> words;
/*
	words.push_back("This");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification.");
*/
/*
	words.push_back("What");
	words.push_back("must");
	words.push_back("be");
	words.push_back("shall");
	words.push_back("be.");
*/
	words.push_back("Don't");
	words.push_back("go");
	words.push_back("around");
	words.push_back("saying");
	words.push_back("the");
	words.push_back("world");
	words.push_back("owes");
	words.push_back("you");
	words.push_back("a");
	words.push_back("living;");
	words.push_back("the");
	words.push_back("world");
	words.push_back("owes");
	words.push_back("you");
	words.push_back("nothing;");
	words.push_back("it");
	words.push_back("was");
	words.push_back("here");
	words.push_back("first.");

	vector<string> res = s.fullJustify(words, 30);
	for (int i=0; i<res.size(); ++i) {
		cout << res[i] << endl;
	}
}
