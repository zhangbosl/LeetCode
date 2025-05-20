#include<iostream>
#include <unordered_set>
#include <unordered_map>
//#include <string>

using namespace std;

class Solution1 {
public:
	int  lengthOfLongestSubstring(string s) {
		//char* a = &s[0], * b = &s[0];
		int length = 0;
		int a = 0, b = 0;

		for (; b < s.size(); b++) {
			for (int tmp = a; tmp < b; tmp++) {
				if (s[tmp] == s[b]) {
					length = max(length, b - a);
					a = tmp + 1;
					cout << a << ' ' << b << endl;
				}
			}
		}
		length = max(length, b - a);

		return length;
    }
};

class Solution2 {
public:
	int  lengthOfLongestSubstring(string s) {
		//char* a = &s[0], * b = &s[0];
		int length = 0;
		int a = 0, b = 0;
		unordered_set<char> occ;

		for (; b < s.size(); b++) {
			if (occ.find(s[b]) != occ.end()) {
				length = max(length, b - a);
				for (; a < b; a++) {
					occ.erase(s[a]);
					if (s[a] == s[b]) {
						a = a + 1;
						cout << a << ' ' << b << endl;
						break;
					}
				}
			}
			occ.insert(s[b]);
		}
		length = max(length, b - a);

		return length;
	}
};

class Solution3 {
public:
	int  lengthOfLongestSubstring(string s) {
		//struct CharPos {
		//	char c;
		//	int pos;
		//};
		//char* a = &s[0], * b = &s[0];
		int length = 0;
		int a = 0, b = 0;
		unordered_set<char> occ;

		for (; b < s.size(); b++) {
			if (occ.find(s[b]) != occ.end()) {
				length = max(length, b - a);
				for (; s[a] != s[b]; a++) {
					occ.erase(s[a]);
				}
				a = a + 1;
				//cout << a << ' ' << b << endl;
			}
			occ.insert(s[b]);
		}
		length = max(length, b - a);

		return length;
	}
};

class Solution {
public:
	int  lengthOfLongestSubstring(string s) {
		//struct CharPos {
		//	char c;
		//	int pos;
		//};
		//char* a = &s[0], * b = &s[0];
		int length = 0;
		int a = 0, b = 0;
		unordered_map<char, int> occ;

		for (; b < s.size(); b++) {
			if (occ.find(s[b]) != occ.end()) {
				length = max(length, b - a);
				int tmp = occ.find(s[b])->second;
				//cout << a << ' ' << b << endl;
				for (; a <= tmp; a++) {
					occ.erase(s[a]);
				}
				//cout << a << ' ' << b << endl;
			}
			occ.insert({ s[b], b });
		}
		length = max(length, b - a);

		return length;
	}
};

class Solution_ext {
public:
	int  lengthOfLongestSubstring(string s) {
		//char* a = &s[0], * b = &s[0];
		int length = 0;
		int a = 0, b = 0;
		unordered_set<char> occ;

		for (; a < s.size(); a++) {
			for (; b < s.size(); b++) {
				if (occ.find(s[b]) != occ.end()) {
					occ.erase(s[a]);
					break;
				}
				occ.insert(s[b]);
			}
			length = max(length, b - a);
			if (b == s.size()) {
				break;
			}
		}
		return length;
	}
};

int main() {
	//string s = "";
	string s = "awwbwg";
	//string s = "abcabcbb";
	//string s = "bbbbb";
	//string s = "pwwkew";
	
	Solution solution;

	cout << solution.lengthOfLongestSubstring(s) << endl;

	return 0;
}