#include <bits/stdc++.h>

using namespace std;

string s;
int visited[100];

void re(int st, int end) {
	if (st >= end || end <= st) return;

	// print
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		if (visited[i]) ans += s[i];
	}
	if (ans.size()) cout << ans << "\n";


	// find first char
	int idx = st;
	char mw;

	for (int i = st + 1; i < end; i++) {
		if (s[i] < s[idx] && !visited[i]) idx = i;
	}

	visited[idx] = 1;
	re(idx + 1, end);
	re(st, idx);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	re(0, s.length());
	cout << s;

	return 0;
}