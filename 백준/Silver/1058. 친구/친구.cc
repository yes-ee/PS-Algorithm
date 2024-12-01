#include <bits/stdc++.h>

using namespace std;

int n, ans;
int dp[50][50];
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			} else
			if (s[j] == 'Y') {
				dp[i][j] = 1;
			} else {
				dp[i][j] = 1e9;
			}
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 1 || dp[i][j] == 2) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans;
}