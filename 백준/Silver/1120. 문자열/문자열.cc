#include <bits/stdc++.h>

using namespace std;

string a, b;
int len, ans = 1e9;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> a >> b;

	int alen = a.length();
	int blen = b.length();

	int diff = blen - alen;

	for (int i = 0; i <= diff; i++) {
		int cnt = 0;
		for (int j = 0; j < alen; j++) {
			if (a[j] != b[i + j]) cnt++;
		}
		ans = min(cnt, ans);
	}

	cout << ans;

	return 0;
}