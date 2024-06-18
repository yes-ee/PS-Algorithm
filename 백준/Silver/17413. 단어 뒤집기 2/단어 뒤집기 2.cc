#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
string ans;

int main() {
	getline(cin, s);

	int tag = 0;
	string st = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			reverse(st.begin(), st.end());
			ans += st;
			tag = 1;
			st = s[i];
		} else if (s[i] == '>') {
			st += s[i];
			ans += st;
			tag = 0;
			st = "";
		} else if (!tag && s[i] == ' ') {
			reverse(st.begin(), st.end());
			st += s[i];
			ans += st;
			st = "";
		} else {
			st += s[i];
		}

	}

	if (st.size()) {
		reverse(st.begin(), st.end());
		ans += st;
	}

	cout << ans;
	return 0;
}