#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
	cin >> t;
	while (t--) {
		cin >> s;

		if (s.length() == 1)
			cout << s << s << "\n";
		else
			cout << s[0] << s[s.length() - 1] << "\n";
	}

	return 0;
}