#include <bits/stdc++.h>

using namespace std;

int n;
string s, ans;

int main() {
	cin >> n >> s;

	ans = s.substr(n-5);

	cout << ans;

	return 0;
}