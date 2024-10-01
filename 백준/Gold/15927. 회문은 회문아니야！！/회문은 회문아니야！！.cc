#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	int flag = 1;

	// check palindrome
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			cout << s.length();
			return 0;
		}
	}

	// palindrome
	for (int i = 1; i < (s.length() + 1) / 2; i++) {
		if (s[i - 1] != s[i]) {
			cout << s.length() - 1;
			return 0;
		}
	}

	cout << "-1";

	return 0;
}