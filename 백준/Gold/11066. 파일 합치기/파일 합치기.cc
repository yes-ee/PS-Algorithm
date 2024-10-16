#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
int k;
ll dp[501][501];
ll sum[501]; // 파일 누적합

ll re(int st, int end) {
	if (st == end) return 0;
	if (dp[st][end]) return dp[st][end];

	ll ms = 1e9;

	for (int i = st; i < end; i++) {
		ms = min(ms, re(st, i) + re(i + 1, end));
	}

	return dp[st][end] = ms + sum[end] - sum[st - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;

	int a;

	while (t--) {
		cin >> k;

		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= k; j++) {
				dp[i][j] = 0;
			}
		}

		for (int i = 1; i <= k; i++) {
			cin >> a;
			sum[i] = sum[i - 1] + a;
		}

		re(1, k);

		cout << dp[1][k] << "\n";
	}

	return 0;
}