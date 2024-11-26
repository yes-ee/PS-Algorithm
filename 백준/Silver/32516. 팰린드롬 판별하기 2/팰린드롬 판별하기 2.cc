#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int ans;

int main() {
	cin >> n;
	cin >> s;

	int st = 0;
	int end = s.size() - 1;

	while (st < end) {
		char a = s[st];
		char b = s[end];
		if (a != '?' && b != '?') {
			if (a != b) {
				ans = 0;
				break;
			}
		} else if (a == '?' && b == '?') {
			ans += 26;
		} else {
			ans++;
		}
		st++;
		end--;
	}
	cout << ans;
	
	return 0;
}