#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// bottom up

int t, k;
ll dp[501][501];
int sum[501];

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

		for (int gap = 1; gap < k; gap++) {
			for (int st = 1; st + gap <= k; st++) {
				ll ms = 1e9;
				for (int i = st; i < st + gap; i++) {
					ms = min(dp[st][i] + dp[i + 1][st + gap], ms);
				}
				dp[st][st + gap] = ms + sum[st + gap] - sum[st - 1];
			}
		}


		cout << dp[1][k] << "\n";
	}

	return 0;
}
